close all; clear all; more off; clc;

xnode = [
  0.0,  0.0;
  12,   5;
  0,    15;
  20,   15;
  20,   3;
];

icone = [
       1,      2,      3,     -1;
       2,      4,       3,      -1;
       4,      2,       5,      -1;
];

DIR = [
       1, 100;
       3, 100;
       4, 150;
       5, 150;
];

NEU = [
       1, 2, 0;
       2, 5, 0;
       3, 4, 5
];

ROB = [];

PUN = [];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.kx = 2.37;
model.ky = 2.37;
model.c = 0;

% Cantidad de elementos
model.G = [
    0;
    0;
    0;
];

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 268890; % Expresado en kg/m^3
model.cp = 1.0;
model.maxit =            1;
model.tol = 1.000000e-05;

% Condición inicial
model.PHI_n = mean(DIR(:,2))*ones(model.nnodes,1);

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
#fem2d_heat_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

disp('Finalizado el post-procesamiento.');


% =======================[Posproceso]=========================

exK = [ 1.6063  -0.9875  -0.6188        0        0;
       -0.9875   5.6288  -1.4418  -1.7183  -1.4813;
       -0.6188  -1.4418   2.0843  -0.0237        0;
             0  -1.7183  -0.0237   2.2851  -0.5431;
             0  -1.4813        0  -0.5431   2.0244];

aK = exK(2, [1 3:end]);
aF = [100 100 150 150]';
(aK*aF)/exK(2, 2)

Fxy = exK*PHI


% =======================[evaluacion flujo de calor]=========================
% yp = 0.5, por ser simetrico el sistema, se toma que yp = 0.1
xp = 12; yp = 12;  % Coordenadas del punto donde se evalúa el flujo de calor
elemento = 2;  % Número del elemento triangular en la malla (matriz `icone`)

nodos = icone(elemento, 1:3);  % Obtiene los nodos del elemento
J = [ xnode(nodos(2), :) - xnode(nodos(1), :);  % Calcula la matriz Jacobiana
      xnode(nodos(3), :) - xnode(nodos(1), :)];

DN = [-1 1 0; -1 0 1];  % Derivadas de las funciones de forma en coordenadas locales (xi, eta)
temp = PHI(icone(elemento, 1:3));  % Temperaturas en los nodos del elemento

B = J\DN;  % Calcula la matriz B (inversa de la Jacobiana por las derivadas)

qxy = (B * temp)'  % Calcula el flujo de calor en las direcciones `x` y `y`

pos_nodes = xnode(nodos, :);  % Obtiene las coordenadas globales de los nodos

prob = sum(pos_nodes) / 3;  % Calcula el centroide del triángulo (promedio de los nodos)
xp = prob(1); yp = prob(2);  % Asigna las coordenadas del centroide a xp y yp

N = fem2d_heat_blerp(pos_nodes, xp, yp)  % Calcula las funciones de forma en el punto (xp, yp)
Naux = blerp_cartes(pos_nodes, xp, yp)  % Calcula las funciones de forma con otra función (alternativa)

P = N' * PHI(nodos)  % Interpola la temperatura en el punto (xp, yp)

hold on;  % Mantiene la gráfica actual
plot(xp, yp, 'ro');  % Dibuja un punto rojo en el gráfico en las coordenadas (xp, yp)



