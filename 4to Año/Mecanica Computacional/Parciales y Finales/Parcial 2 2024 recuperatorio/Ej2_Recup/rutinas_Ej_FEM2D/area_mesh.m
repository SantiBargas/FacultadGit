function [area] = area_mesh(xnod,icone,flag)
%
%   [area] = area_mesh(xnod,icone,flag)
%
%   flag ~=0  area per node ( else, area per element)
%

if nargin<3, flag=0; end

[numnp,ndm]=size(xnod);
[numel,nen]=size(icone);

if ndm ~=2,
    if nen==3,
        % triangulos en una superficie 3D
        a = xnod(icone(:,2),:)-xnod(icone(:,1),:);
        b = xnod(icone(:,nen),:)-xnod(icone(:,1),:);
        nor = pvec(a,b);
        %nor = sqrt(sum(nor'.^2))';
        area = norm_l2(nor)/2;
    elseif nen==4,
        a = xnod(icone(:,2),:)-xnod(icone(:,1),:);
        b = xnod(icone(:,nen),:)-xnod(icone(:,1),:);
        nor = pvec(a,b);
        %nor = sqrt(sum(nor'.^2))';
        area1 = norm_l2(nor/2);

        a = xnod(icone(:,2),:)-xnod(icone(:,nen),:);
        b = xnod(icone(:,3),:)-xnod(icone(:,nen),:);
        nor = pvec(a,b);
        %nor = sqrt(sum(nor'.^2))';
        area2 = norm_l2(nor/2);

        area = area1+area2;
    else
        error(' Only for 2D or TRI or QUAD in 3D ');
    end

else

    if nen==3,
        a = xnod(icone(:,2),:)-xnod(icone(:,1),:);
        b = xnod(icone(:,nen),:)-xnod(icone(:,1),:);
        a = [a,0*a(:,1)];
        b = [b,0*b(:,1)];
        nor = pvec(a,b);
        area = (nor(:,3))/2;
    elseif nen==4,
        a = xnod(icone(:,2),:)-xnod(icone(:,1),:);
        b = xnod(icone(:,4),:)-xnod(icone(:,1),:);
        a = [a,0*a(:,1)];
        b = [b,0*b(:,1)];
        nor = pvec(a,b);
        area = (nor(:,3)/2);
        a = xnod(icone(:,3),:)-xnod(icone(:,2),:);
        b = xnod(icone(:,4),:)-xnod(icone(:,2),:);
        a = [a,0*a(:,1)];
        b = [b,0*b(:,1)];
        nor = pvec(a,b);
        area = area+(nor(:,3)/2);
    else
        error('Bad element type')
    end
end

row=[];col=[];coe=[];
if flag
    for k=1:nen
        nodes=icone(:,k);
        row = [row;nodes];
        col = [col;ones(size(icone,1),1)];
        coe = [coe;area/nen];
    end
    area_nod = sparse(row,col,coe);
    area = full(area_nod);
end