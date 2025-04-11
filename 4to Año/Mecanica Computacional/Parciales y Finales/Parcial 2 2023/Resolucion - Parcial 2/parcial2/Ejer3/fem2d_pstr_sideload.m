function [F] = fem2d_pstr_sideload(F,Sideload,xnode,th)
    for i=1:size(Sideload,1)
        x=xnode(Sideload(i,1),:)-xnode(Sideload(i,2),:); % Side Coordinates
        l = sqrt(x*transpose(x));            % Side Size
        indN1 = [Sideload(i,1)*2-1 Sideload(i,1)*2];       % Node 1 of side
        indN2 = [Sideload(i,2)*2-1 Sideload(i,2)*2];       % Node 2 of side
        indx = [indN1 indN2];                % Side Nodes
        Fx = (th*l*Sideload(i,3)/2);
        Fy = (th*l*Sideload(i,4)/2);
        force = [Fx Fy Fx Fy]';
        F(indx) = F(indx) + force;     
    end
end
