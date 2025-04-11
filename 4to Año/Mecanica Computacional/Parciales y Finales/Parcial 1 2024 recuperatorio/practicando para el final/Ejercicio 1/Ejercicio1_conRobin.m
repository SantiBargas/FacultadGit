pkg load symbolic;  % Cargar el paquete simbólico

% Parámetros
k = 2;
deltax = 0.25;
nodos = 5;
x = linspace(0,1,nodos);
G = @(x) 100 * (1 - x);
G_values = arrayfun(G, x); % Evalúa G(x) en cada nodo

disp('Matriz K sin condiciones de contorno')
K = [-2 1 0 0 0 ; 1 -2 1 0 0 ; 0 1 -2 1 0 ; 0 0 1 -2 1 ; 0 0 0 1 -2];

disp('Cálculo de F como G(x) * deltax^2 / k para cada nodo')
F = [(G_values * deltax^2) / k]';

% Aproximación de Robin (2do orden)
puntos = [0, -1, -2]; % Usamos T_N, T_{N-1}, T_{N-2}
k_deriv = 1;          % Primera derivada
disp('Los coeficientes de Robin son:')
coef_robin = taylorDF(puntos, k_deriv)

disp('Los coeficientes de Robin evaluados en h=0.25:')
syms h;
coef_robin = subs(coef_robin, h, deltax) % Evaluamos los coeficientes en h=0.25
coef_robin = double(coef_robin);  % Convertimos a valores numéricos

% Condiciones de contorno

% Condición de Dirichlet en x=0
nodo_dirichlet = 1;
valor_dirichlet = 10;
K(nodo_dirichlet, :) = 0;
K(nodo_dirichlet, nodo_dirichlet) = 1;
F(nodo_dirichlet) = valor_dirichlet;

% Condición de Robin en x=1
nodo_robin = 5;
h_intercambio = 5;  % Coeficiente de intercambio térmico
g_flujo = -2;       % Flujo impuesto

K(nodo_robin, :) = 0
K(nodo_robin, nodo_robin) = coef_robin(1) - h_intercambio * deltax / k; % Agregamos h a la ecuación
K(nodo_robin, nodo_robin-1) = coef_robin(2)
K(nodo_robin, nodo_robin-2) = coef_robin(3)

% Modificar el vector F con la condición impuesta
F(nodo_robin) = g_flujo / k

% Resolver el sistema
T = K \ F;

% Mostrar resultados
disp('Solución T en cada nodo:')
disp(T);

