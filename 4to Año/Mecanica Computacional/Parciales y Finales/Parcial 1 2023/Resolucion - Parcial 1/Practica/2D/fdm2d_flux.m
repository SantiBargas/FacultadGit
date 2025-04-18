function [Q] = fdm2d_flux(PHI,neighb,xnode,k)
    N = size(xnode,1);
    Qx = zeros(N,1);
    Qy = zeros(N,1);
    
    for P = 1 : N
        S = neighb(P,1);
        E = neighb(P,2);
        N = neighb(P,3);
        W = neighb(P,4);
        
        if (E ~= -1 && W ~= -1)
            dxe = xnode(E,1) - xnode(P,1);
            dxw = xnode(P,1) - xnode(W,1);
            Qx(P) = -k(P) * (PHI(E) - PHI(W)) / (dxe + dxw);
        elseif (E ~= -1)
            dx = xnode(E,1) - xnode(P,1);
            Qx(P) = -k(P) * (PHI(E) - PHI(P)) / dx;
        else
            dx = xnode(P,1) - xnode(W,1);
            Qx(P) = -k(P) * (PHI(P) - PHI(W)) / dx;
        end
        
        if (N ~= -1 && S ~= -1)
            dyn = xnode(N,2) - xnode(P,2);
            dys = xnode(P,2) - xnode(S,2);
            Qy(P) = -k(P) * (PHI(N) - PHI(S)) / (dyn + dys);
        elseif (N ~= -1)
            dy = xnode(N,2) - xnode(P,2);
            Qy(P) = -k(P) * (PHI(N) - PHI(P)) / dy;
        else
            dy = xnode(P,2) - xnode(S,2);
            Qy(P) = -k(P) * (PHI(P) - PHI(S)) / dy;
        end
    end
    
    Q = [Qx, Qy];
end

