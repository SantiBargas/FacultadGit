
% caso elemento triangular en 2D
syms r s x y x1 y1 x2 y2 x3 y3 u1 u2 u3 v1 v2 v3 Vel Kd

ndm = 2;

N(1) = 1-r-s;
N(2) = r;
N(3) = s;

Kd(1,1) = 'Kxx';
Kd(2,2) = 'Kyy';
Kd(1,2) = 'Kxy';
Kd(2,1) = 'Kxy';

Vel(1) = 'Ux';
Vel(2) = 'Uy';

Kd = eye(2);
Vel = zeros(2,1);

xv = [ x1; x2; x3];
yv = [ y1; y2; y3];
uv = [ u1; u2; u3];
vv = [ v1; v2; v3];

nen = 3;

xp = 0; yp = 0; up = 0; vp = 0;

for k=1:nen
    xp = xp + N(k)*xv(k);
    yp = yp + N(k)*yv(k);
    up = up + N(k)*uv(k);
    vp = vp + N(k)*vv(k);
end

dxdr = diff(xp,'r');
dydr = diff(yp,'r');
dxds = diff(xp,'s');
dyds = diff(yp,'s');

J = [dxdr , dxds; dydr, dyds];

J1 = inv(J);

for k=1:nen
    dNdxi(1,k) = diff(N(k),'r')*J1(1,1)+diff(N(k),'s')*J1(2,1);
    dNdxi(2,k) = diff(N(k),'r')*J1(1,2)+diff(N(k),'s')*J1(2,2);
end

% termino de rigidez y masa
disp(' This task takes some seconds - please wait')
detJ=det(J);

for i=1:nen
    % termino fuente
    vaux = N(i)*detJ;
    fl_Q(i) = int(int(vaux,'s',0,'1-r'),'r',0,1);  
    
    for j=1:nen
        vaux = N(i)*N(j)*detJ;
        Mlm(i,j) = int(int(vaux,'s',0,'1-r'),'r',0,1);
        vaux = (dNdxi(1,i)*(Kd(1,1)*dNdxi(1,j)+Kd(1,2)*dNdxi(2,j)) + ...
            dNdxi(2,i)*(Kd(2,1)*dNdxi(1,j)+Kd(2,2)*dNdxi(2,j)))*detJ;
        Klm(i,j) = int(int(vaux,'s',0,'1-r'),'r',0,1);
%        vaux = (N(i)*Vel(1)*dNdxi(1,j) + ...
%            N(i)*Vel(2)*dNdxi(2,j))*detJ;
        vaux = (N(i)*up*dNdxi(1,j) + ...
            N(i)*vp*dNdxi(2,j))*detJ;
        Clm(i,j) = int(int(vaux,'s',0,'1-r'),'r',0,1);
    end
end

matlabFunction(Klm,'file','KLM_Scalar_2D_ele');
matlabFunction(Mlm,'file','MLM_Scalar_2D_ele');
matlabFunction(Clm,'file','CLM_Scalar_2D_ele');
matlabFunction(fl_Q,'file','flQ_Scalar_2D_ele');



return

jobinfo = 0; % particularizamos para algunos elementos
if nargin <3
    jobinfo = 1; % calcula las matrices de toda la malla
    ele = (1:size(icone,1))';
end

if jobinfo==0
    for kele=1:length(ele),
        n1 = icone(ele(kele),1);n2 = icone(ele(kele),2);n3 = icone(ele(kele),3);
        Klm_p(kele).array =  subs(subs(subs(subs(subs(subs(Klm, ...
            x1,xnod(n1,1)),y1,xnod(n1,2)), ...
            x2,xnod(n2,1)),y2,xnod(n2,2)), ...
            x3,xnod(n3,1)),y3,xnod(n3,2));
        
        Mlm_p(kele).array =  subs(subs(subs(subs(subs(subs(Mlm, ...
            x1,xnod(n1,1)),y1,xnod(n1,2)), ...
            x2,xnod(n2,1)),y2,xnod(n2,2)), ...
            x3,xnod(n3,1)),y3,xnod(n3,2));
    end
    Kg=[];Mg=[];
    return
end

% assembling four triangles
Kg = zeros(length(ele));
Mg = zeros(length(ele));
Klm_p = [];Mlm_p = [];
for k=1:4
    nodos = icone(k,:);
    xnod_p = xnod(nodos,:);    
    Klm_t = subs(subs(subs(subs(subs(subs(Klm,x1,xnod_p(1,1)),y1,xnod_p(1,2)),x2,xnod_p(2,1)),y2,xnod_p(2,2)),x3,xnod_p(3,1)),y3,xnod_p(3,2));
    Mlm_t = subs(subs(subs(subs(subs(subs(Mlm,x1,xnod_p(1,1)),y1,xnod_p(1,2)),x2,xnod_p(2,1)),y2,xnod_p(2,2)),x3,xnod_p(3,1)),y3,xnod_p(3,2));
    for i=1:nen
        for j=1:nen
            Kg(nodos(i),nodos(j)) = Kg(nodos(i),nodos(j)) + Klm_t(i,j);
            Mg(nodos(i),nodos(j)) = Mg(nodos(i),nodos(j)) + Mlm_t(i,j);
        end
    end
end
