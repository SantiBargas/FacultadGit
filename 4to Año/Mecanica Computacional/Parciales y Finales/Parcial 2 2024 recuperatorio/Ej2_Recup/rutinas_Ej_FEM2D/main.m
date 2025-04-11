%
% usando el codigo simbolico para triangulos generar las matrices del
% sistema asi como los miembros derechos
%
% ESTO ES SOLO PARA TRIANGULOS
%

% esto se ejecuta solo una vez
if ~exist('MLM_Scalar_2D_ele.m','file')
    symbolic_FEM_Scalar_2D
end

id_mesh=0; % un solo elemento y master
id_mesh=1; % 1 solo elemento como en el examen
%id_mesh=2; % 4 triangulos obtenidos refinando a la mitad el caso 1

% malla generica
if id_mesh==0
    % testeo en el master
    XY = [0,0; 1,0; 0,1 ];
elseif id_mesh==1
    % uso una malla dada
    XY = 1e-3*[0,0; 1,0; 0.5,sqrt(3)/2 ];
    xnod = XY;
    icone = [1,2,3];
elseif id_mesh==2
    error('Construya usted mismo la malla y luego adapte el codigo ')
else
    error(' Mala eleccion del id_mesh ')
end

L12 = norm(XY(2,:)-XY(1,:));
L23 = norm(XY(3,:)-XY(2,:));
L31 = norm(XY(1,:)-XY(3,:));


Klm_p = KLM_Scalar_2D_ele(XY(1,1),XY(2,1),XY(3,1),XY(1,2),XY(2,2),XY(3,2));
Mlm_p = MLM_Scalar_2D_ele(XY(1,1),XY(2,1),XY(3,1),XY(1,2),XY(2,2),XY(3,2));
fl_Q  = flQ_Scalar_2D_ele(XY(1,1),XY(2,1),XY(3,1),XY(1,2),XY(2,2),XY(3,2));

rho = 1000;
Cp = 4186;
rhoCp = rho*Cp;
% difusividad termica
k = 0.58;
alpha = k/rhoCp;
% reactividad
c = 1*10;
cp = c/rhoCp;
% fuente
Q = 100;
Qp = Q/rhoCp;
% flujo normal entrante Neumann
q = (-10);
qp = q/rhoCp;
% flujo Robin
h = 200;
hp = h/rhoCp;
Tinfty = 273+10;

% analisis transitorio
theta = 1/2;
dt = 1e-10;
dt = 1e15;
if 1
    % paso de tiempo critico de un explicito
    dt_crit = 0.25*area_mesh(xnod,icone)/alpha;
    %dt = dt_crit;
end
dt = min([0.5,dt_crit])
Tfinal = 2;
ntime = round(Tfinal/dt);

% estado inicial (satisface las condiciones Dirichlet)
Told = 273+zeros(3,1);

% matriz de masa sin termino de contorno por condicion Robin
MG = Mlm_p*(1/dt);
CG = Mlm_p*cp;
% matriz de rigidez global
KG = Klm_p*alpha;
%KG = MG+(CG+KG)*theta;

% flujo normal Robin para la arista 2, nodos (2-3)
HG = zeros(3);
HG(2,2) = hp*L23/3;
HG(3,3) = hp*L23/3;
HG(2,3) = hp*L23/6;
HG(3,2) = hp*L23/6;
%KG = KG + theta*HG;

KG_T = (CG+KG+HG);

% miembro derecho
% termino fuente
fG = fl_Q'*Qp;
% aporte de las condiciones de contorno
% flujo normal Neumann
fG(1) = fG(1) - L12/2*qp;
fG(2) = fG(2) - L12/2*qp;
% flujo normal Robin
fG(2) = fG(2) + L23/2*hp*Tinfty;
fG(3) = fG(3) + L23/2*hp*Tinfty;

fG_0 = fG;

Tnew = Told;
ttime = 0;
for kt=1:ntime
    ttime = ttime+dt;
    % aporte de la condicion inicial o estado anterior
    %fG = fG_0+MG*Told+(1-theta)*(-(KG+CG)*Told);
    fG = fG_0 + MG*Told - (1-theta)*KG_T*Told;

    LHS = (MG+theta*KG_T);
    RHS = fG;

    % aplico condiciones de contorno
    % Dirichlet en los nodos 1 y 3 al valor inicial Told
    LHS(1,:) = 0; LHS(1,1)=1;
    LHS(3,:) = 0; LHS(3,3)=1;
    RHS(1) = Told(1);
    RHS(3) = Told(3);

    Tnew = LHS\RHS;
    disp([' Tnew ( t = ' num2str(ttime) ')  = ' num2str(Tnew(2)) ])
    Told(2) = Tnew(2);
end



