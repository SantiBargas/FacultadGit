close all; clear all; more off;

##Lx = 2;
##Ly = 1;
##
##xnode = [
## -2 , -1;
## 0 ,-1;
##  2 , -1;
##
##  -2 ,0;
##  0,0;
##  2,0;
##
##  -2,1;
##  0,1;
##  2,1
## ];

lx=2;
deltax=lx/2;
ly=1;
deltay=ly/2;



xnode = [
  -deltax,-deltay;
  0,-deltay;
  deltax,-deltay;
  -deltax,0;
  0,0;
  deltax,0;
  -deltax,deltay;
  0,deltay;
  deltax,deltay;
];

icone = [
      1,2,5,4;
      2,3,6,5;
      4,5,8,7;
      5,6,9,8
];


DIR = [
];

NEU = [
      3, 10.0000000000000000, 2;
      6, 10.0000000000000000, 2;
      9, 10.0000000000000000, 2;
      1, 10.0000000000000000, 4;
      4, 10.0000000000000000, 4;
      7, 10.0000000000000000, 4;
];
% * ROB: matriz con la información sobre la frontera de tipo Robin.
%   - Columna 1: índice del nodo donde se aplica la condición de borde.
%   - Columna 2: valor de coeficiente de calor (h)
%   - Columna 3: valor de temperatura de referencia (phi_inf).
%   - Columna 4: dirección y sentido del flujo:
%     (1) Flujo en dirección eje-y, sentido negativo (S – South – Sur)
%     (2) Flujo en dirección eje-x, sentido positivo (E – East – Este)
%     (3) Flujo en dirección eje-y, sentido positivo (N – North – Norte)
%     (4) Flujo en dirección eje-x, sentido negativo (W – West – Oeste)
ROB = [
       1, 100.0000000000000000, 250.0000000000000000, 1;
       2, 100.0000000000000000, 250.0000000000000000, 1;
       3, 100.0000000000000000, 250.0000000000000000, 1;
       7, 100.0000000000000000, 250.0000000000000000, 3;
       8, 100.0000000000000000, 250.0000000000000000, 3;
       9, 100.0000000000000000, 250.0000000000000000, 3;
];


disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);

model.k = 1*ones(size(xnode,1));

model.c = 0*ones(size(xnode,1));

model.G = 100*ones(size(xnode,1));

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 1.0000000000000000;
model.cp = 1.0000000000000000;
model.maxit =            1;
model.tol = 1.000000e-05;

% Condición inicial
####model.PHI_n = mean(DIR(:,2))*ones(model.nnodes,1);
##model.PHI_n =0*ones(model.nnodes,1);

disp('Iniciando el método numérico...');

% Llamada principal al Método de Diferencias Finitas
[PHI,Q] = fdm2d(xnode, icone, DIR, NEU, ROB, model);

disp('Finalizada la ejecución del método numérico.');



disp('---------------------------------------------------------------');
disp('Iniciando el post-procesamiento...');

% mode ---> modo de visualización:
%           [0] 2D - Con malla
%           [1] 3D - Con malla
%           [2] 2D - Sin malla
%           [3] 3D - Sin malla
% graph --> tipo de gráfica:
%           [0] Temperatura (escalar)
%           [1] Flujo de Calor (vectorial)
%           [2] Flujo de Calor eje-x (escalar)
%           [3] Flujo de Calor eje-y (escalar)
%           [4] Magnitud de Flujo de Calor (escalar)
mode = 0;
graph = 0;
fdm2d_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

disp('Finalizado el post-procesamiento.');
