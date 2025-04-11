close all; clear all; more off;

xnode = [
 0,0;
 1,0;
 1,1.1;
 0,1.1;

 -1,1.1;
 -1,1.6;
 0,1.6;
 1,1.6;
 1,2;
 0,2;
 -1,2
];

icone = [
       1,2,3,4;
       4,3,8,7;
       5,4,7,6;
       6,7,10,11;
       7,8,9,10;
];
%   - Columna 1: número de nodo.
%   - Columna 2: valor en ese nodo (escalar)
DIR = [
       11,40;
       10,40;
       9,40;
];

% * NEU: matriz con la información sobre la frontera de tipo Neumann.
%   - Columna 1: índice del nodo donde se aplica la condición de borde.
%   - Columna 2: valor de flujo térmico (q) asociado al lado del elemento.
%   - Columna 3: dirección y sentido del flujo:
%     (1) Flujo en dirección eje-y, sentido negativo (S – South - Sur)
%     (2) Flujo en dirección eje-x, sentido positivo (E – East - Este)
%     (3) Flujo en dirección eje-y, sentido positivo (N – North - Norte)
%     (4) Flujo en dirección eje-x, sentido negativo (W – West – Oeste)

NEU = [
       1,0,1;
       2,0,1;
       1,0,4;
       4,0,1;
       5,0,1;

       5,-30,4;
       6,-30,4;
       11,-30,4;

       2,0,2;
       3,0,2;
       8,0,2;
       9,0,2;
];

ROB = [
];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);

model.k = 1.6*ones(size(xnode,1));

model.c = 0*ones(size(xnode,1));

model.G = zeros(size(xnode,1),1); % Inicializa con ceros
% Asigna un valor de fuente a los nodos 1, 2, 3 y 4
model.G([1,2,3,4]) = 100; % Reemplaza G_value con el valor deseado


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


####################################################################

% Coordenadas de los 4 nodos vecinos
x = [-1, 0, -1, 0];   % Coordenadas en X de los nodos
y = [1.6, 1.6, 2, 2]; % Coordenadas en Y de los nodos
T = [PHI(6), PHI(7), PHI(10), PHI(11)]; % Temperaturas en los nodos (reemplazar)

% Matriz del sistema
A = [
    1, x(1), y(1), x(1)*y(1);
    1, x(2), y(2), x(2)*y(2);
    1, x(3), y(3), x(3)*y(3);
    1, x(4), y(4), x(4)*y(4)
];

% Vector de temperaturas
b = [T(1); T(2); T(3); T(4)];

% Resolver el sistema
a = A \ b;

% Mostrar los coeficientes
disp("Coeficientes a0, a1, a2, a3:")
disp(a)

% Evaluar la temperatura en x = -0.5, y = 1.8
x_interp = -0.5;
y_interp = 1.8;
T_interp = a(1) + a(2)*x_interp + a(3)*y_interp + a(4)*x_interp*y_interp;

disp("Temperatura interpolada en (-0.5, 1.8):")
disp(T_interp)

