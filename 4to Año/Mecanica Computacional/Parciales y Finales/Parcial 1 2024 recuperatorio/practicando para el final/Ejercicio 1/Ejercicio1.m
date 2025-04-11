#PARAMETROS
k=2;
deltax=0.25;
nodos=5;
x=linspace(0,1,nodos);
G = @(x) 100 * (1 - x);
nodos = 5;
x = linspace(0, 1, nodos); % Genera los valores de x en los nodos
G = @(x) 100 * (1 - x);    % Definición de la función G(x)

% Evaluación de G(x) en cada nodo y almacenamiento en un vector
G_values = arrayfun(G, x); % Evalúa G(x) en cada punto de x y almacena en G_values

% Mostrar los valores de G(x) en cada nodo
disp('Valores de G(x) en cada nodo:');
disp(G_values);

disp('Matriz K sin condiciones de contorno')
K=[-2 1 0 0 0 ; 1 -2 1 0 0 ; 0 1 -2 1 0 ; 0 0 1 -2 1 ; 0 0 0 1 -2]

disp('Cálculo de F como G(x) * deltax^2 / k para cada nodo')
F = [(G_values * deltax^2) / k]'

###Para neumann queremos aproximar con 2do orden entonces buscamos los coeficientes para a ->xi  b->xi-1 c->xi-2
puntos = [0, -1, -2]; % Usamos T_N, T_{N-1}, T_{N-2}
k_deri = 1;                % Primera derivada
disp('Los coeficientes de neumann son:')
coef_neumann = taylorDF(puntos, k_deri)
disp('Los coeficientes de neumann evaluados en x=0.25 son:')
syms h;
coef_neumann = subs(coef_neumann, h, deltax) %evaluamos los coeficientes en h=0.25
coef_neumann = double(coef_neumann)  % Convertimos a valores numéricos


###########CONDICIONES DE CONTORNO##############

%%Tenemos dirlichet en x=0
nodo_dirichlet = 1; %primer nodo de xnode % En MATLAB los índices comienzan en 1
valor_dirichlet = 10;

%%Tenemos neumann en x=1
nodo_neumann = 5; %5 nodo para x=1
flujo_q = -1; % Valor de la derivada impuesta


% Aplicar condición de Dirichlet en la matriz K y el vector F
K(nodo_dirichlet, :) = 0; % Poner en cero la fila
K(nodo_dirichlet, nodo_dirichlet) = 1 % Poner un 1 en la diagonal
F(nodo_dirichlet) = valor_dirichlet % Poner el valor de la condición de Dirichlet


##% Aplicar condición de Neumann en la matriz K
K(nodo_neumann, :) = 0 % Poner en cero la fila
K(nodo_neumann, nodo_neumann) = coef_neumann(1) % Coeficiente en T_i
K(nodo_neumann, nodo_neumann-1) = coef_neumann(2) % Coeficiente en T_i-1
K(nodo_neumann, nodo_neumann-2) = coef_neumann(3) % Coeficiente en T_i-2

% Modificar el vector F con la condición impuesta
F(nodo_neumann) = flujo_q / k

T = K\F

##
##K2=[1 0 0 0 0 ; 1 -2 1 0 0 ; 0 1 -2 1 0 ; 0 0 1 -2 1 ; 0 0 0 2 -2]
##F2=F;
####F2(5)=(1/2)*2*0.25
##T2= K2\F2
##
##K3=[1 0 0 0 0 ; 1 -2 1 0 0 ; 0 1 -2 1 0 ; 0 0 1 -2 1 ; 0 0 (32/3) -16 16/3  ]
##T3=K3\F
