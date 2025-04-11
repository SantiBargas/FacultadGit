function [K,F] = fdm2d_gen_system(K,F,xnode,neighb,k,c,G)
  for P = 1 : size(xnode,1)
        S = neighb(P,1);
        E = neighb(P,2);
        N = neighb(P,3);
        W = neighb(P,4);
        
        %% Distance to each neighbour (if any)   
        ds = 0; de = 0; dn = 0; dw = 0;

        if(S ~= -1)
            ds = abs(xnode(S,2) - xnode(P,2));
        end

        if(E ~= -1)
            de = abs(xnode(E,1) - xnode(P,1));
        end

        if(N ~= -1)
            dn = abs(xnode(N,2) - xnode(P,2));
        end

        if(W ~= -1)
            dw = abs(xnode(W,1) - xnode(P,1));
        end

        %% x-axis coefficients
        if (E ~= -1 && W == -1)
            ax = 2/(de*de);
            bx = -2/(de*de);
            cx = 0;
        elseif (E == -1 && W ~= -1)
            ax = 0;
            bx = -2/(dw*dw);
            cx = 2/(dw*dw);
        else
            ax = 2/(de*(de+dw));
            bx = -2/(de*dw);
            cx = 2/(dw*(de+dw));
        end

        %% y-axis coefficients
        if (N ~= -1 && S == -1)
            ay = 2/(dn*dn);
            by = -2/(dn*dn);
            cy = 0;
        elseif (N == -1 && S ~= -1)
            ay = 0;
            by = -2/(ds*ds);
            cy = 2/(ds*ds);
        else
            ay = 2/(dn*(dn+ds));
            by = -2/(dn*ds);
            cy = 2/(ds*(dn+ds));
        end
        
        %% K matrix's coefficients assembly
        % Every node has a contribution of Reaction Constant 'c'. Also always has
        % 'bx' and 'by' coefficients and per node source G.
        K(P,P) = c(P) - k(P)*bx - k(P)*by;
        F(P) = G(P);
        
        if (S ~= -1)
            K(P,S) = -k(P)*cy;
        end

        if (E ~= -1)
            K(P,E) = -k(P)*ax;
        end
        
        if (N ~= -1)
            K(P,N) = -k(P)*ay;
        end
        
        if (W ~= -1)
            K(P,W) = -k(P)*cx;
        end
    end
end
