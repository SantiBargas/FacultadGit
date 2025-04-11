function [K,F] = fem2d_pstr_fixnodes(K,F,Fixnodes)
    for i=1:size(Fixnodes,1)
        p = 2*Fixnodes(i,1)+Fixnodes(i,2)-2;
        K(p,:) = 0;
        K(p,p) = 1;
        F(p) = Fixnodes(i,3);
    end
end