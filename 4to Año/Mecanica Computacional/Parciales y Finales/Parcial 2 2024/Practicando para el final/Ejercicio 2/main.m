close all; clear all; more off;

xnode = [
    0.0,  0.0; #1
    1,0; #2
    1.5,0; #3
    2,0; #4

    0,0.25; #5
    0.75,0.25; #6
    1,0.5; #7
    1.5,0.5; #8
    2,0.5; #9

    0,0.75; #10
    0.75,0.75; #11

    0,1 ;#12
    1,1; #13
    1.5,1; #14
    2,1; #15
];

icone = [
       1,      2,      6,     5; #1
       2,      7,      6,     -1; #2
       2,      3,      8,     7; #3
       3,      4,      9,     8; #4

       10,11,13,12; #5
       11,7,13,-1; #6
       7,8,14,13;#7
       8,9,15,14 #8

];

DIR = [#NODO - VALOR
  5,100;
  6,100;
  7,100;
  11,100;
  10,100;
];

NEU = [ #Nodo1 #Nodo2 #Valor
  1,5,0;
  10,12,0;

  1,2,3;
  2,3,3;
  3,4,3;

  12,13,3;
  13,14,3;
  14,15,3;
];

##NEU = [
##       1, 5, 0;
##       10, 12, 0;
##
##       1,2,2.5*(0.5^2);
##       2,3,2.5*(1.25^2);
##       3,4,2.5*(1.75^2);
##
##       12,13,2.5*(0.5^2);
##       13,14,2.5*(1.25^2);
##       14,15,2.5*(1.75^2)
##];

ROB = [#Nodo1 #Nodo2 #H #Valor
  4,9,3,20;
  9,15,3,20;
];

PUN = [             #valor           coordenada de puntos

];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.kx = 1;
model.ky = 1;
model.c = 0;

model.G = [
    0;
    0;
    0;
    0;
    0;
    0;
    0;
    0;
];

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 1.0000000000000000;
model.cp = 1.0000000000000000;
model.maxit =            10000;
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
fem2d_heat_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

disp('Finalizado el post-procesamiento.');

##%===================== Cálculo de interpolacion de temperatura ========================%
x_p = 1.75  ; y_p = 0.5;
elemento = 4;

% Obtener los nodos asociados al elemento
nodos_aux = icone(elemento, icone(elemento, :) > 0);
disp('Coordenadas a evaluar en las funciones de forma')
coords_aux = xnode(nodos_aux, :)

disp('Funciones de forma de coords aux:')
[Ns] = funciones_forma(coords_aux)

pkg load symbolic;
syms x y;
disp('Funciones de forma evaluadas en las coordenadas x y:')
Ns_eval = double(subs(Ns, [x, y], [x_p, y_p]))

% Interpolación de temperatura
disp('Temperatura en los nodos del elemento')
T_elem = PHI(nodos_aux) % Temperaturas en los nodos del elemento

disp('La temperatura interpolada sera Tp= N1*T1 + N2*T2 + N3*T3 ...')
T_p = Ns_eval' * T_elem

% Mostrar resultado
disp(['La temperatura interpolada en el punto (' num2str(x_p) ', ' num2str(y_p) ') es: ' num2str(T_p)]);

##===============================================================================================%
##
% ====================[ Cálculo del flujo de calor para un elemento]======================
x_p = 0  ; y_p = 0.25;
elemento = 1;

##x_p = 1  ; y_p = 0.25;
##elemento = 1;
##
##x_p = 1  ; y_p = 0.5;
##elemento = 2;
##
##x_p = 0  ; y_p = 0.75;
##elemento = 5;
##
##x_p = 0.75  ; y_p = 0.75;
##elemento = 6;

nodos_aux = icone(elemento, icone(elemento, :) > 0);
coords_aux = xnode(nodos_aux, :);
[Ns] = funciones_forma(coords_aux);

% Calcular las derivadas simbólicas de las funciones de forma
pkg load symbolic;
syms x y;
dNs_dx = diff(Ns, x); % Derivada respecto a x
dNs_dy = diff(Ns, y); % Derivada respecto a y

disp('Derivadas de las funciones de forma respecto a x:');
disp(dNs_dx);
disp('Derivadas de las funciones de forma respecto a y:');
disp(dNs_dy);

% Evaluar las derivadas en el punto (x_p, y_p)
dNs_dx_eval = double(subs(dNs_dx, [x, y], [x_p, y_p]));
dNs_dy_eval = double(subs(dNs_dy, [x, y], [x_p, y_p]));

disp('Derivadas evaluadas en el punto (x_p, y_p):');
disp('dNs_dx_eval:');
disp(dNs_dx_eval);
disp('dNs_dy_eval:');
disp(dNs_dy_eval);

% Gradiente de temperatura en el punto
T_elem = PHI(nodos_aux); % Temperaturas nodales
grad_T = [dNs_dx_eval, dNs_dy_eval]' * T_elem;

disp('Gradiente de temperatura en el punto (x_p, y_p):');
disp(grad_T);

% Calcular el flujo de calor
q = -diag([model.kx, model.ky]) * grad_T; % q = -[kx, 0; 0, ky] * grad_T

disp('Flujo de calor en el punto (x_p, y_p):');
disp(['q_x: ', num2str(q(1)), ' W/m^2']);
disp(['q_y: ', num2str(q(2)), ' W/m^2']);

% Calcular el flujo resultante (magnitud)
q_resultante = sqrt(q(1)^2 + q(2)^2);
disp(['Flujo de calor resultante en el punto (x_p, y_p): ', num2str(q_resultante), ' W/m^2']);
%===============================================================================================%
