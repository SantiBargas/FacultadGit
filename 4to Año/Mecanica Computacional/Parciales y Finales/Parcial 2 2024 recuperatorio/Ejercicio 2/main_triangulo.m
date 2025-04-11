close all; clear all; more off;

xnode = 1*10^-3*[
    0.0, 0.0;
    1.0, 0.0;
    0.5, 0.866;
]

icone = [
  1,2,3, -1
];

DIR = [#NODO - VALOR
       1,273;
##       2,273;
       3,273;
];

NEU = [ #Nodo1 #Nodo2 #Valor
  1,2,10;
];

ROB = [#Nodo1 #Nodo2 #H #Valor
       2,3,200,283;
];

PUN = [             #valor           coordenada de puntos

];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.kx = 0.58;
model.ky = 0.58;
model.c = 10 ;

model.G = 100 * ones(size(xnode,1), 1);

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 0; #theta = 0 explicito %inciso a)
##model.ts = 1; #theta = 1 implicito %inciso
##model.ts = 2; #theta = 1/2 Crank-Nicholson.

% Tiempo final de simulación
t_final = 2;  % segundos

% Parámetros para esquemas temporales
model.rho = 1000;      % Densidad (kg/m^3)
model.cp = 4186;       % Calor específico (J/kg-K)
##model.maxit = 1000;

model.tol = 1.000000e-05;

alpha = model.kx / (model.rho * model.cp);  % Coeficiente de difusión térmica
deltax = norm(xnode(2,:) - xnode(1,:)); % Distancia euclidiana
% Cálculo del paso de tiempo dt
#dt = 0.5 * deltax ^2 / alpha %%alpha = k /pcp
dt = (0.5 * deltax^2) / alpha;
model.maxit = ceil(t_final / dt); %inciso b)
model.dt = dt;

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
if any(isnan(PHI)) || any(isinf(PHI))
    error("Error en la simulación: PHI contiene valores NaN o Inf.");
end


mode = 0;
graph = 0;
fem2d_heat_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

disp('Finalizado el post-procesamiento.');

##%===================== Cálculo de interpolacion de temperatura ========================%
##x_p = 0.6  ; y_p = 0.01;
##elemento = 5;
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

% ====================[ Cálculo del flujo de calor para un elemento]======================
x_p = 0.9  ; y_p = 0.04;
elemento = 5;

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
