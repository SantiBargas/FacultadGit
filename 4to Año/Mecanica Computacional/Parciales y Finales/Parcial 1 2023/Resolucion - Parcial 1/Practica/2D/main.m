close all; clear all; more off;

xnode = [
  -4.00, -3.00;
  -2.00, -3.00;
  0.00,  -3.00;
  2.00,  -3.00;
  4.00,  -3.00;
  -4.00, -1.00;
  -2.00, -1.00;
  0.00,  -1.00;
  2.00,  -1.00;
  4.00,  -1.00;
  -4.00, 1.00;
  -2.00, 1.00;
  0.00,  1.00;
  2.00,  1.00;
  4.00,  1.00;
  -4.00, 3.00;
  -2.00, 3.00;
  0.00,  3.00;
  2.00,  3.00;
  4.00,  3.00;
];

icone = [
       1,   2,   7,   6;
       2,   3,   8,   7;
       3,   4,   9,   8;
       4,   5,  10,   9;
       6,   7,  12,  11;
       7,   8,  13,  12;
       8,   9,  14,  13;
       9,  10,  15,  14;
      11,  12,  17,  16;
      12,  13,  18,  17;
      13,  14,  19,  18;
      14,  15,  20,  19;
];

DIR = [
       1, 20.0000000000000000;
       6, 20.0000000000000000;
      11, 20.0000000000000000;
      16, 20.0000000000000000;
];

NEU = [
       1, 0.0000000000000000, 1;
       2, 0.0000000000000000, 1;
       3, 0.0000000000000000, 1;
       4, 0.0000000000000000, 1;
       5, 0.0000000000000000, 1;
      16, 0.0000000000000000, 3;
      17, 0.0000000000000000, 3;
      18, 0.0000000000000000, 3;
      19, 0.0000000000000000, 3;
      20, 0.0000000000000000, 3;
];

ROB = [
        5, 2.0000000000000000, 10.0000000000000000, 2;
       10, 2.0000000000000000, 10.0000000000000000, 2;
       15, 2.0000000000000000, 10.0000000000000000, 2;
       20, 2.0000000000000000, 10.0000000000000000, 2;
];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);

model.k = 3 * ones(length(xnode),1);

model.c = zeros(length(xnode),1);

model.G = 100*xnode(:,1);

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 1.0000000000000000;
model.cp = 1.0000000000000000;
model.maxit =            1;
model.tol = 1.000000e-05;

% Condición inicial
model.PHI_n = mean(DIR(:,2))*ones(model.nnodes,1);

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

PHI = full(PHI);
res = [(PHI(8)+PHI(13))/2];
fprintf('Temperatura en (0,0): %f \n', res);
