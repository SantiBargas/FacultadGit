function [K,F] = fdm2d_robin(K,F,xnode,neighb,ROB)
    % ROBIN
    M = size(ROB, 1);
    for n = 1 : M
        P = ROB(n, 1);           % centro
        S = neighb(P, 1);        % sur
        E = neighb(P, 2);        % este
        N = neighb(P, 3);        % norte
        W = neighb(P, 4);        % oeste

        h = ROB(n,2);
        phi_inf = ROB(n,3);

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
                
        if (ROB(n,4) == 1) % SOUTH
            K(P,P) = K(P,P) + 2*h/dy;
            F(P) = F(P) + 2*h*phi_inf/dy;
        end
        
        if (ROB(n,4) == 2) % EAST
            K(P,P) = K(P,P) + 2*h/dx;
            F(P) = F(P) + 2*h*phi_inf/dx;
        end
        
        if (ROB(n,4) == 3) % NORTH
            K(P,P) = K(P,P) + 2*h/dy;
            F(P) = F(P) + 2*h*phi_inf/dy;
        end
        
        if (ROB(n,4) == 4) % WEST
            K(P,P) = K(P,P) + 2*h/dx;
            F(P) = F(P) + 2*h*phi_inf/dx;
        end
    end
end