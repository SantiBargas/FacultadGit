function [F] = fdm2d_neumann(F,xnode,neighb,NEU)
    % NEUMANN
    M = size(NEU, 1);
    for n = 1 : M
        P = NEU(n, 1);           % centro
        S = neighb(P, 1);        % sur
        E = neighb(P, 2);        % este
        N = neighb(P, 3);        % norte
        W = neighb(P, 4);        % oeste

        q = NEU(n,2);

        if (S == -1)
            dy = abs(xnode(N,2) - xnode(P,2));
        end
        
        if (E == -1)
            dx = abs(xnode(W,1) - xnode(P,1));
        end
        
        if (N == -1)
            dy = abs(xnode(S,2) - xnode(P,2));
        end
        
        if (W == -1)
            dx = abs(xnode(E,1) - xnode(P,1));
        end
                
        if (NEU(n,3) == 1) % SOUTH
            F(P) = F(P) - 2*q/dy;
        end
        
        if (NEU(n,3) == 2) % EAST
            F(P) = F(P) - 2*q/dx;
        end
        
        if (NEU(n,3) == 3) % NORTH
            F(P) = F(P) - 2*q/dy;
        end
        
        if (NEU(n,3) == 4) % WEST
            F(P) = F(P) - 2*q/dx;
        end
    end
end