close all; clear all; more off;

xnode = [
  0.0000000000000000, 0.0000000000000000;
  0.0000000000000000, 0.1666666666666667;
  0.0000000000000000, 0.3333333333333333;
  0.0000000000000000, 0.5000000000000000;
  0.3333333333333333, 0.0000000000000000;
  0.3333333333333333, 0.1666666666666667;
  0.3333333333333333, 0.3333333333333333;
  0.3333333333333333, 0.5000000000000000;
  0.6666666666666666, 0.0000000000000000;
  0.6666666666666666, 0.1666666666666667;
  0.6666666666666666, 0.3333333333333333;
  0.6666666666666666, 0.5000000000000000;
  1.0000000000000000, 0.0000000000000000;
  1.0000000000000000, 0.1666666666666667;
  1.0000000000000000, 0.3333333333333333;
  1.0000000000000000, 0.5000000000000000;
];

icone = [
       1,      5,      6,     -1;
       1,      6,      2,     -1;
       2,      6,      7,      3;
       3,      7,      4,     -1;
       5,      9,     10,      6;
       7,      8,      4,     -1;
       7,     11,     12,      8;
       9,     13,     10,     -1;
      10,     14,     15,     11;
      11,     15,     16,     -1;
      11,     16,     12,     -1;
      13,     14,     10,     -1;
];

% Extraer coordenadas de los nodos
x = xnode(:,1);
y = xnode(:,2);

% Dibujar los nodos como puntos
plot(x, y, 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', 8);
hold on
% Dibujar las conexiones entre nodos según la matriz icone
for i = 1:size(icone, 1)
    % Obtener los índices de los nodos que forman el elemento
    indices = icone(i, :);
    indices(indices == -1) = [];  % Eliminar los nodos inexistentes (-1)

    % Si hay al menos dos nodos para conectar, dibujar la línea
    if length(indices) >= 2
        x_elem = x(indices);
        y_elem = y(indices);

        % Dibujar la línea que conecta los nodos
        plot(x_elem, y_elem, 'b-', 'LineWidth', 1.5);
    end
end

DIR = [
       4, 20.0000000000000000;
       6, 9.0000000000000000;
       7, 9.0000000000000000;
       8, 20.0000000000000000;
      12, 20.0000000000000000;
      16, 20.0000000000000000;
];

NEU = [
       2, 1.0000000000000000, 7;
       3, 2.0000000000000000, 7;
       4, 3.0000000000000000, 7;
      10, 6.0000000000000000, 0;
      11, 10.0000000000000000, 5;
];

ROB = [
       1, 5.0000000000000000, 15.0000000000000000, 16;
       5, 9.0000000000000000, 15.0000000000000000, 16;
       7, 11.0000000000000000, 20.0000000000000000, 8;
       9, 13.0000000000000000, 15.0000000000000000, 16;
      13, 14.0000000000000000, 10.0000000000000000, 30;
      14, 15.0000000000000000, 10.0000000000000000, 30;
      15, 16.0000000000000000, 10.0000000000000000, 30;
];

PUN = [
       9, 2.0000000000000000, 0.7500000000000000, 0.2000000000000000
];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.kx = 13.0000000000000000;
model.ky = 17.0000000000000000;
model.c = 19.0000000000000000;

model.G = [
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
    23.0000000000000000;
];

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 1;

% Parámetros para esquemas temporales
model.rho = 60.0000000000000000;
model.cp = 55.0000000000000000;
model.maxit =          1;
model.tol = 1.000000e-06;
model.dt = 0.1000000000000000;

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
