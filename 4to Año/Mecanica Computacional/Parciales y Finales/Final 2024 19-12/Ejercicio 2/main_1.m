close all; clear all; more off;

Lx = 2;
Ly = 1;

xnode = [
  -Lx , -Ly;
  -Lx, Ly;
  Lx , Ly;
  Lx , -Ly;
];

icone = [
      1,2,3,4;
];

DIR = [
];
NEU = [
1 , 2 , 10;
3 , 4 ,10 ;
];

ROB = [
       2, 3, 100, 250;
       1, 4, 100, 250
       ];

PUN = [
];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.kx = 1.0000000000000000;
model.ky = 1.0000000000000000;
model.c = 1.0000000000000000;

model.G = [
100;
100;
100;
100
];

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 7800;
model.cp = 500;
model.maxit =          1;
model.tol = 1.000000e-06;
model.dt = 0.1000000000000000;

% Condición inicial
##model.PHI_n = mean(DIR(:,2))*ones(model.nnodes,1);
model.PHI_n = 0*ones(model.nnodes,1);

disp('Iniciando el método numérico...');

% Llamada principal al Método de Elementos Finitos
[PHI,Q] = fem2d_heat(xnode,icone,DIR,NEU,ROB,PUN,model);

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
fem2d_heat_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

disp('Finalizado el post-procesamiento.');


%=========== Posproceso, evaluacion puntual=================%
% yp = 0.5, por ser simetrico el sistema, se toma que yp = 0.1
xp = 0.1; yp = 0.1;

nodos = icone(2, 1:3)
pos_nodes = xnode(nodos, :);

N = fem2d_heat_blerp(pos_nodes, xp, yp)
Naux = blerp_cartes(pos_nodes, xp, yp)
P = N'*PHI(nodos)

hold on;
plot(xp, yp, 'ro');
%==============================================================%
