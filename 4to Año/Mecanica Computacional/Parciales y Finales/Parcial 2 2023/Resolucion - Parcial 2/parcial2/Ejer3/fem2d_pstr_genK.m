function [localK] = fem2d_pstr_genK(nodes,D,th)
    if (size(nodes,1) == 3) % elemento triangular
        J = [nodes(2,1)-nodes(1,1)  nodes(2,2)-nodes(1,2);
             nodes(3,1)-nodes(1,1)  nodes(3,2)-nodes(1,2)];
        DN = [-1 1 0;-1 0 1];
        V = J\DN; % inv(J)*DN
        B = [V(1,1)     0     V(1,2)     0     V(1,3)     0   ;
               0      V(2,1)    0      V(2,2)    0      V(2,3);
             V(2,1)   V(1,1)  V(2,2)   V(1,2)  V(2,3)   V(1,3)];
        A = 0.5;
        localK = (B'*D*B)*det(J)*A*th;
    else
        % cuatro puntos de Gauss con peso w=1
        p = sqrt(3)/3;
        pospg = [-p,p];
        localK = zeros(8,8);
        for i=1:2
            for j=1:2
                s = pospg(i);
                t = pospg(j);
            
                DNnum = [   (-1+t)/4,( 1-t)/4,( 1+t)/4,(-1-t)/4;
                            (-1+s)/4,(-1-s)/4,( 1+s)/4,( 1-s)/4     ];
                J = DNnum*nodes;
                V = J\DNnum; % inv(J)*DNum
                B = [V(1,1)     0     V(1,2)     0     V(1,3)     0     V(1,4)     0;
                       0      V(2,1)    0      V(2,2)    0      V(2,3)    0      V(2,4);
                     V(2,1)   V(1,1)  V(2,2)   V(1,2)  V(2,3)   V(1,3)  V(2,4)   V(1,4)];
                localK = localK + B'*D*B*det(J)*th;
            end
        end
    end
end
