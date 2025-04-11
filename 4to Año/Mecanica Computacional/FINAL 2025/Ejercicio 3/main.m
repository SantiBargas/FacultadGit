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

       1,2,4,-1;
       2,3,4,-1;
       4,3,8,7;
       5,4,7,6;
       7,8,9,10;
       6,7,10,11;


];
%   - Columna 1: número de nodo.
%   - Columna 2: valor en ese nodo (escalar)
DIR = [
##  11,40;
##  10,40;
##  9,40;
];


% * F: vector de flujo térmico.
% * NEU: matriz con la información sobre la frontera de tipo Neumann.
%   - Columnas 1-2: dos nodos contiguos formando un lado de un elemento.
%   - Columna 3: valor de flujo térmico (q) asociado al lado del elemento.
% * xnode: matriz de nodos con pares (x,y) representando las coordenadas de
%   cada nodo de la malla.
NEU = [
  1,2,0;
  1,4,0;
  4,5,0;

  5,6,0;
  6,11,0;

  2,3,0;
  3,8,0;
  8,9,0;

];

% * ROB: matriz con la información sobre la frontera de tipo Robin.
%   - Columnas 1-2: dos nodos contiguos formando un lado de un elemento.
%   - Columna 3: valor de coeficiente de calor (h).
%   - Columna 4: valor de temperatura de referencia (phi_inf).
% * xnode: matriz de nodos con pares (x,y) representando las coordenadas de cada nodo de la malla.


ROB = [
 11,10,5,10;
 10,9,5,10;
];

PUN = [
];


disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.kx = 1.6;
model.ky = 1.6;
model.c = 1.0000000000000000;

model.G = zeros(size(icone,1),1); % Inicializa con ceros
% Asigna un valor de fuente a los nodos 1, 2, 3 y 4
model.G([1,2]) = 100; % Reemplaza G_value con el valor deseado

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 1.0000000000000000;
model.cp = 1.0000000000000000;
model.maxit =            1;
model.tol = 1.000000e-05;

% Condición inicial
##model.PHI_n = mean(DIR(:,2))*ones(model.nnodes,1);

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
##x_p = -0.5  ; y_p = 1.8;
##elemento = 6;
##
##% Obtener los nodos asociados al elemento
##nodos_aux = icone(elemento, icone(elemento, :) > 0);
##disp('Coordenadas a evaluar en las funciones de forma')
##coords_aux = xnode(nodos_aux, :)
##
##disp('Funciones de forma de coords aux:')
##[Ns] = funciones_forma(coords_aux)
##
##pkg load symbolic;
##syms x y;
##disp('Funciones de forma evaluadas en las coordenadas x y:')
##Ns_eval = double(subs(Ns, [x, y], [x_p, y_p]))
##
##% Interpolación de temperatura
##disp('Temperatura en los nodos del elemento')
##T_elem = PHI(nodos_aux) % Temperaturas en los nodos del elemento
##
##disp('La temperatura interpolada sera Tp= N1*T1 + N2*T2 + N3*T3 ...')
##T_p = Ns_eval' * T_elem
##
##% Mostrar resultado
##disp(['La temperatura interpolada en el punto (' num2str(x_p) ', ' num2str(y_p) ') es: ' num2str(T_p)]);

%===============================================================================================%
##
##% ====================[ Cálculo del flujo de calor para un elemento]======================
##x_p = 0.9  ; y_p = 0.04;
##elemento = 5;
##
##nodos_aux = icone(elemento, icone(elemento, :) > 0);
##coords_aux = xnode(nodos_aux, :);
##[Ns] = funciones_forma(coords_aux);
##
##% Calcular las derivadas simbólicas de las funciones de forma
##pkg load symbolic;
##syms x y;
##dNs_dx = diff(Ns, x); % Derivada respecto a x
##dNs_dy = diff(Ns, y); % Derivada respecto a y
##
##disp('Derivadas de las funciones de forma respecto a x:');
##disp(dNs_dx);
##disp('Derivadas de las funciones de forma respecto a y:');
##disp(dNs_dy);
##
##% Evaluar las derivadas en el punto (x_p, y_p)
##dNs_dx_eval = double(subs(dNs_dx, [x, y], [x_p, y_p]));
##dNs_dy_eval = double(subs(dNs_dy, [x, y], [x_p, y_p]));
##
##disp('Derivadas evaluadas en el punto (x_p, y_p):');
##disp('dNs_dx_eval:');
##disp(dNs_dx_eval);
##disp('dNs_dy_eval:');
##disp(dNs_dy_eval);
##
##% Gradiente de temperatura en el punto
##T_elem = PHI(nodos_aux); % Temperaturas nodales
##grad_T = [dNs_dx_eval, dNs_dy_eval]' * T_elem;
##
##disp('Gradiente de temperatura en el punto (x_p, y_p):');
##disp(grad_T);
##
##% Calcular el flujo de calor
##q = -diag([model.kx, model.ky]) * grad_T; % q = -[kx, 0; 0, ky] * grad_T
##
##disp('Flujo de calor en el punto (x_p, y_p):');
##disp(['q_x: ', num2str(q(1)), ' W/m^2']);
##disp(['q_y: ', num2str(q(2)), ' W/m^2']);
##
##% Calcular el flujo resultante (magnitud)
##q_resultante = sqrt(q(1)^2 + q(2)^2);
##disp(['Flujo de calor resultante en el punto (x_p, y_p): ', num2str(q_resultante), ' W/m^2']);
##%===============================================================================================%
