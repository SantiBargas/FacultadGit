close all; clear all; more off;clc;

xnode = [
0.0000 -0.000;
0.0025 -0.000;
0.0050 -0.000;
0.0075 -0.000;
0.0100 -0.000;

0.0000 -0.004;
0.0025 -0.004;
0.0050 -0.004;
0.0075 -0.004;
0.0100 -0.004;

0.0050 -0.008;
0.0075 -0.008;
0.0100 -0.008;

0.0000 -0.012;
0.0025 -0.012;
0.0050 -0.012;
0.0075 -0.012;
0.0100 -0.012;

0.0000 -0.016;
0.0025 -0.016;
0.0050 -0.016;
0.0075 -0.016;
0.0100 -0.016;

0.0000 -0.020;
0.0025 -0.020;
0.0050 -0.020;
0.0075 -0.020;
0.0100 -0.020;
];

icone = [
  6,7,2,1;
  7,8,3,2;
  8,9,4,3;
  9,10,5,4;
  11,12,9,8;
  12,13,10,9;
  16,17,12,11;
  17,18,13,12;
  19,20,15,14;
  20,21,16,15;
  21,22,17,16;
  22,23,18,17;
  24,25,20,19;
  25,26,21,20;
  26,27,22,21;
  27,28,23,22;
];

NEU = [
  1, 0, 3;
  1, 0, 4;
  2, 0, 3;
  3, 0, 3;
  4, 0, 3;
  5, 0, 3;
  5, 0, 2;
  6, 0, 4;
  10, 0, 2;
  13, 0, 2;
  14, 0, 4;
  18, 0, 2;
  19, 0, 4;
  23, 0, 2;
  24, 0, 4;
  24, -10^5, 1;
  25, -10^5, 1;
  26, -10^5, 1;
  27, -10^5, 1;
  28, 0, 2;
  28, -10^5, 1;
];

ROB = [
  14, 5000, 15 , 3;
  15, 5000, 15 , 3;
  11, 5000, 15 , 4;
  7, 5000, 15 , 1;
  6, 5000, 15 , 1;
];

DIR = [
];

model.nnodes = size(xnode,1);
model.k = 190 * ones(1,length(xnode));
model.c = zeros(1,length(xnode));
model.G = zeros(1,length(xnode));
% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;
% Parámetros para esquemas temporales
model.rho = 1.000;
model.cp = 1.000;
model.maxit = 1;
model.tol = 1.00e-05;
% Condición inicial
model.PHI_n = zeros(model.nnodes,1);
disp('Iniciando el método numérico...');

% Llamada principal al Método de Diferencias Finitas
[PHI,Q] = fdm2d(xnode, icone, DIR, NEU, ROB, model);

disp('Finalizada la ejecución del método numérico.');
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
disp('Flujo de calor en nodo 9');
qx=Q(9,1);
qy=Q(9,2);
q = sqrt(qx^2 + qy^2);
disp(q)
disp('Flujo de calor en nodo 17');
qx=Q(17,1);
qy=Q(17,2);
q = sqrt(qx^2 + qy^2);
disp(q)
disp('Flujo de calor en nodo 20');
qx=Q(20,1);
qy=Q(20,2);
q = sqrt(qx^2 + qy^2);
disp(q)
disp('Finalizado el post-procesamiento.');

