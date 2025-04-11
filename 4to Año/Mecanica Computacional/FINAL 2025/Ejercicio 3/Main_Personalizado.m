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

%===================== Cálculo de interpolacion de temperatura ========================%
##x_p = 10  ; y_p = 12;
##elemento = 2;
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
##x_p = 10; y_p = 12;
##elemento = 2;
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
##



% ====================[ Cálculo del flujo de calor para un elemento triangular ]======================
##
##xp = 10; yp = 12;  % Coordenadas del punto donde se evalúa el flujo de calor
##elemento = 2;  % Número del elemento triangular en la malla (matriz `icone`)
##nodos = icone(elemento, 1:3)  % Obtiene los nodos del elemento
##J = [ xnode(nodos(2), :) - xnode(nodos(1), :);  % Calcula la matriz Jacobiana
##      xnode(nodos(3), :) - xnode(nodos(1), :)];
##
##DN = [-1 1 0; -1 0 1];  % Derivadas de las funciones de forma en coordenadas locales (xi, eta)
##temp = PHI(icone(elemento, 1:3));  % Temperaturas en los nodos del elemento
##B = J\DN;  % Calcula la matriz B (inversa de la Jacobiana por las derivadas)
##disp('FLUJO DE TEMPERATURA EN EL ELEMENTO')
##qxy = (B * temp)' % Calcula el flujo de calor en las direcciones `x` y `y`
##
##pos_nodes = xnode(nodos, :);  % Obtiene las coordenadas globales de los nodos
##prob = sum(pos_nodes) / 3;  % Calcula el centroide del triángulo (promedio de los nodos)
##xp = prob(1); yp = prob(2);  % Asigna las coordenadas del centroide a xp y yp
##N = fem2d_heat_blerp(pos_nodes, xp, yp);  % Calcula las funciones de forma en el punto (xp, yp)
##disp('TEMPERATURA INTERPOLADA EN LOS PUNTOS XP YP')
##P = N' * PHI(nodos)  % Interpola la temperatura en el punto (xp, yp)
##
##hold on;  % Mantiene la gráfica actual
##plot(xp, yp, 'ro');  % Dibuja un punto rojo en el gráfico en las coordenadas (xp, yp)

% ====================[ Cálculo del flujo de calor para un elemento cuadrangular ]======================
##xp = 12; yp = 12;  % Coordenadas del punto donde se evalúa el flujo de calor
##elemento = 2;  % Número del elemento cuadrangular en la malla (matriz `icone`)
##nodos = icone(elemento, 1:4);  % Obtiene los nodos del elemento cuadrangular (4 nodos)
##
##% Obtener las coordenadas globales de los nodos
##pos_nodes = xnode(nodos, :);
##
##% Calcular la matriz Jacobiana para un elemento cuadrangular
##J = [ pos_nodes(2, :) - pos_nodes(1, :);
##      pos_nodes(3, :) - pos_nodes(1, :)];
##
##% Derivadas de las funciones de forma en coordenadas locales (xi, eta) para cuadriláteros
##DN = [-1 1 1 -1; -1 -1 1 1];  % Funciones de forma en coordenadas locales
##
##% Temperaturas en los nodos del elemento cuadrangular
##temp = PHI(nodos);
##
##% Calculamos la matriz B para cuadriláteros
##B = inv(J) * DN;  % B = inv(Jacobiana) * Derivadas
##
##% Cálculo del flujo de calor en las direcciones `x` y `y`
##disp('FLUJO DE TEMPERATURA EN EL ELEMENTO')
##qxy = (B * temp)';  % Calcula el flujo de calor en las direcciones `x` y `y`
##
##% Cálculo del centroide del elemento cuadrangular
##prob = sum(pos_nodes) / 4;  % Promedio de las coordenadas de los nodos (centroide)
##xp = prob(1); yp = prob(2);  % Asigna las coordenadas del centroide a xp y yp
##
##% Cálculo de las funciones de forma en el punto (xp, yp) utilizando la función fem2d_heat_blerp
##N = fem2d_heat_blerp(pos_nodes, xp, yp);  % Funciones de forma en el punto (xp, yp)
##
##disp('TEMPERATURA INTERPOLADA EN LOS PUNTOS XP YP')
##% Interpolación de la temperatura en el punto (xp, yp)
##P = N' * PHI(nodos);  % Interpolación de la temperatura en el centroide
##
##% Graficar el centroide en el gráfico
##hold on;  % Mantiene la gráfica actual
##plot(xp, yp, 'ro');  % Dibuja un punto rojo en el gráfico en las coordenadas (xp, yp)
##
##% ====================================================================================================
##

