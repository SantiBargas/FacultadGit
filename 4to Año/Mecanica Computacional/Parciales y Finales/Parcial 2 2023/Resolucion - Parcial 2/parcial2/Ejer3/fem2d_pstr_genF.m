function [localF] = fem2d_pstr_genF(nodes,Fg,th)
    if (size(nodes,1) == 3) % Triangular element
        A = 0.5*det([1 nodes(1,1) nodes(1,2);
                     1 nodes(2,1) nodes(2,2);
                     1 nodes(3,1) nodes(3,2);]);
        Fel = Fg*A*th;
        Fy = (Fel/3);
        localF = [0; -Fy; 0; -Fy; 0; -Fy];
    else % Quadrangular element
        A1 = 0.5*det([1 nodes(1,1) nodes(1,2);
                     1 nodes(2,1) nodes(2,2);
                     1 nodes(3,1) nodes(3,2);]);
        A2 = 0.5*det([1 nodes(1,1) nodes(1,2);
                     1 nodes(3,1) nodes(3,2);
                     1 nodes(4,1) nodes(4,2);]);
        A = A1+A2;
        Fel = Fg*A*th;
        Fy = (Fel/4);
        localF = [0; -Fy; 0; -Fy; 0; -Fy; 0; -Fy];
    end
end
