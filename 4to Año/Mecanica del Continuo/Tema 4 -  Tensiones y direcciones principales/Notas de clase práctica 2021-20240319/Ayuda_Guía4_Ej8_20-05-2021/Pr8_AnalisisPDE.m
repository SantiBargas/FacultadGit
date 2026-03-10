%% Datos usados para resolver placa por elementos finitos
%Constantes elásticas
E = 1;
po = 1/3;
%
%Datos de geometría
aNum = 1;
bNum = 20;
cNum = 20;
PNum = 1;
%Datos de la malla de EF
hMaxEF = aNum/20;
%Datos de los gráficos
nDivLinHor = 1000;
nDivLinVer = 1000;

%% Llamado a la función creada con PDETool
%Hay que exportar manualmente la malla y los resultados.
%f_SolPDEa10c4
%f_SolPDEa20c4
%f_SolPDEa10c10
%
%Coordenadas de los nodos
%m_Coord = p;
% Se recupera los resultados de desplazamiento.
%uPDE = u(1:end/2);
%vPDE = u(end/2+1:end);
%Devuelve los gradientes en el centro del elemento.
%[uPDEx,uPDEy] = pdegrad(m_Coord,t,uPDE);
%[vPDEx,vPDEy] = pdegrad(m_Coord,t,vPDE);
%Devuelve el gradiente en los nodos de los elementos.
%uPDEx = pdeprtni(m_Coord,t,uPDEx);
%uPDEy = pdeprtni(m_Coord,t,uPDEy);
%vPDEx = pdeprtni(m_Coord,t,vPDEx);
%vPDEy = pdeprtni(m_Coord,t,vPDEy);

%% Se genera por línea de comando el problema
o_Resu = f_PlacaAgujPDE(aNum,bNum,cNum,PNum,E,po,hMaxEF);
%Resultados de desplazamiento
uPDE = o_Resu.NodalSolution(:,1);
vPDE = o_Resu.NodalSolution(:,2);
%Gradientes nodales
uPDEx = o_Resu.XGradients(:,1);
vPDEx = o_Resu.XGradients(:,2);
uPDEy = o_Resu.YGradients(:,1);
vPDEy = o_Resu.YGradients(:,2);
%Malla
m_Coord = o_Resu.Mesh.Nodes;

%% Tensiones calculadas a partir del resultado del PDE
%Deformaciones del PDE.
m_DefPDE = [uPDEx';vPDEy';uPDEy'+vPDEx'];
%Tensor tangente constitutivo (deformación plana).
%m_C  = E/(1+po)/(1-2*po)*[1-po,po,0;po,1-po,0;0,0,(1-2*po)/2];
%Tensor tangente constitutivo (tensión plana).
m_C  = E/(1-po^2)*[1,po,0;po,1,0;0,0,(1-po)/2];
%Tensiones del PDE.
m_TensPDE = m_C*m_DefPDE;

%% Definición de funciones de interpolación
%f_TensPDExx = TriScatteredInterp(p(1,:)',p(2,:)',m_TensPDE(1,:)');
o_TensPDExx = scatteredInterpolant(m_Coord(1,:)',m_Coord(2,:)',m_TensPDE(1,:)');
o_TensPDEyy = scatteredInterpolant(m_Coord(1,:)',m_Coord(2,:)',m_TensPDE(2,:)');
o_TensPDExy = scatteredInterpolant(m_Coord(1,:)',m_Coord(2,:)',m_TensPDE(3,:)');

%% Comparación de resultados de la solución exacta y numérica
% Línea horizontal
m_X = aNum:(bNum-aNum)/nDivLinHor:bNum;
m_Y = zeros(size(m_X));
%Para evaluación de las tensiones
m_R = sqrt(bsxfun(@plus,m_X.^2,m_Y.^2));
m_Theta = bsxfun(@atan2,m_Y,m_X);
%
figure(10)
plot(m_X,f_Sx(m_R,m_Theta),m_X,o_TensPDExx(m_X,m_Y),...
   m_X,f_Sy(m_R,m_Theta),m_X,o_TensPDEyy(m_X,m_Y),...
   m_X,f_Sxy(m_R,m_Theta),m_X,o_TensPDExy(m_X,m_Y))
grid on
title('Línea horizontal')
legend({'Sol. Analítica \sigma_{x}','Sol. MEF \sigma_{x}',...
   'Sol. Analítica \sigma_{y}','Sol. MEF \sigma_{y}',...
   'Sol. Analítica \sigma_{xy}','Sol. MEF \sigma_{xy}'},'Location','SouthEast')
%
% Línea vertical
m_X = zeros(size(m_X));
m_Y = aNum:(cNum-aNum)/nDivLinVer:cNum;
%Para evaluación de las tensiones
m_R = sqrt(bsxfun(@plus,m_X.^2,m_Y.^2));
m_Theta = bsxfun(@atan2,m_Y,m_X);
%
figure(11)
plot(m_Y,f_Sx(m_R,m_Theta),m_Y,o_TensPDExx(m_X,m_Y),...
   m_Y,f_Sy(m_R,m_Theta),m_Y,o_TensPDEyy(m_X,m_Y),...
   m_Y,f_Sxy(m_R,m_Theta),m_Y,o_TensPDExy(m_X,m_Y))
grid on
title('Línea vertical')
legend({'Sol. Analítica \sigma_{x}','Sol. MEF \sigma_{x}',...
   'Sol. Analítica \sigma_{y}','Sol. MEF \sigma_{y}',...
   'Sol. Analítica \sigma_{xy}','Sol. MEF \sigma_{xy}'})