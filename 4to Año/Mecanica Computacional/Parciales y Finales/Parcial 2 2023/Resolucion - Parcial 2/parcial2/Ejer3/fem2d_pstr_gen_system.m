function [K,F] = fem2d_pstr_gen_system(K,F,D,xnode,icone,model)
    % Matrices and vectors elementary -- assembly
    pkg load symbolic
    warning('off', 'all');
    syms x y
    Fx = 500*(x-1);
    Fy = 500*(2-x);
    for e=1:model.nelem
        if (icone(e,4) == -1)
            elem = icone(e,1:3);
            nodes = xnode(elem,:);
            M = [1 nodes(1,1) nodes(1,2);
                 1 nodes(2,1) nodes(2,2);
                 1 nodes(3,1) nodes(3,2)];
            a2 = M\[0; 1; 0];
            N2 = a2(1)+a2(2)*x+a2(3)*y;
            a3 = M\[0; 0; 1];
            N3 = a3(1)+a3(2)*x+a3(3)*y;
        else
            elem = icone(e,:);
            nodes = xnode(elem,:);
            M = [1 nodes(1,1) nodes(1,2) nodes(1,1)*nodes(1,2);
                 1 nodes(2,1) nodes(2,2) nodes(2,1)*nodes(2,2);
                 1 nodes(3,1) nodes(3,2) nodes(3,1)*nodes(3,2);
                 1 nodes(4,1) nodes(4,2) nodes(4,1)*nodes(4,2);];
            a3 = M\[0; 0; 1; 0];
            N3 = a3(1)+a3(2)*x+a3(3)*y+a3(4)*x*y;
            a4 = M\[0; 0; 0; 1];
            N4 = a4(1)+a4(2)*x+a4(3)*y+a4(4)*x*y;
        end
        nodes = xnode(elem,:);

        % Local Matrices and Vectors
        localK = fem2d_pstr_genK(nodes,D,model.thick);
        localF = fem2d_pstr_genF(nodes,model.gravity,model.thick);

        if e==4
          F_var = [Fx*subs(N2,y,0.6);
                   Fy*subs(N2,y,0.6);
                   Fx*subs(N3,y,0.6);
                   Fx*subs(N3,y,0.6)];
          F_var = double(int(F_var,x,0.3,0.6))
          localF(3:6) += F_var;
        elseif e==5
          F_var = [Fx*subs(N3,y,0.6);
                   Fy*subs(N3,y,0.6);
                   Fx*subs(N4,y,0.6);
                   Fx*subs(N4,y,0.6)];
          F_var = double(int(F_var,x,0.6,0.9))
          localF(5:8) += F_var;
        endif
        if e==6
          localK
        elseif e==4
          localF
        endif

        % Assembly
        indx = [];
        for i = 1 : length(elem)
            indx = [indx elem(i)*2-1 elem(i)*2];
        end

        K(indx,indx) = K(indx,indx) + localK;
        F(indx) = F(indx) + localF;
    end
end

