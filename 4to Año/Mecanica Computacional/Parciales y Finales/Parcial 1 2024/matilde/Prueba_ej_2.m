xnode = 2:0.5:4; #discrtizacion
syms x

K = zeros(5,5); #todos de 5x5 pq hay 5 nodos
M = zeros(5,5);
F = zeros(5,1);
G = 100*(4-x);

#N de cada elemento
% Funciones de forma como vectores
N1 = [(2.5 - x)/0.5; (x - 2)/0.5];   % N para el elemento 1
N2 = [(3 - x)/0.5; (x - 2.5)/0.5];   % N para el elemento 2
N3 = [(3.5 - x)/0.5; (x - 3)/0.5];   % N para el elemento 3
N4 = [(4 - x)/0.5; (x - 3.5)/0.5];   % N para el elemento 4

#K del elemento
K_el = [4 -4;-4 4] #K = -k*[2 -2 ; -2 2]
M_el=[1/6 1/12; 1/12 1/6]; # M = h/6 * [2 1 ; 1 2]

% Calcular las integrales y almacenarlas en vectores
F_e1 = [double(int(G * N1(1), x, 2, 2.5)); double(int(G * N1(2), x, 2, 2.5))]; % Vector para F_e1
F_e2 = [double(int(G * N2(1), x, 2.5, 3)); double(int(G * N2(2), x, 2.5, 3))]; % Vector para F_e2
F_e3 = [double(int(G * N3(1), x, 3, 3.5)); double(int(G * N3(2), x, 3, 3.5))]; % Vector para F_e3
F_e4 = [double(int(G * N4(1), x, 3.5, 4)); double(int(G * N4(2), x, 3.5, 4))]; % Vector para F_e4

% Mostrar resultados
disp(['F_e1 = ', num2str(F_e1')]);
disp(['F_e2 = ', num2str(F_e2')]);
disp(['F_e3 = ', num2str(F_e3')]);
disp(['F_e4 = ', num2str(F_e4')]);


### ENSAMBLE
K(1:2,1:2) += K_el;
K(2:3,2:3) += K_el;
K(3:4,3:4) += K_el;
K(4:5,4:5) += K_el;

###MATRIZ M
M(1:2,1:2) += M_el;
M(2:3,2:3) += M_el;
M(3:4,3:4) += M_el;
M(4:5,4:5) += M_el;

###Vector de fuerzas
F(1:2) += F_e1;
F(2:3) += F_e2;
F(3:4) += F_e3;
F(4:5) += F_e4;

#CONDICIONES
# CONDICION DIRICHLET
K(1,:) = 0 ; #ponemos todos en 0 para imponer la temperatura
K(1,1) = 1; #ponemos 1 en el nodo x=2 para luego poner 10 en la temperatura
F(1) = 10; #ponemos 10 en la temperatura para el nodo x=2

# CONDICION NEUMANN
F(5) += 1; #Sumamos 1 al nodo que tiene condicion neumann en este caso x=4

#########INCISO B########################
T=[10; 39.848; 52.149; 54.173; 52.852];

delta_t = 0.1;

T_n_mas_1 = inv(M + delta_t * K) * (M * T + delta_t * F)  % Resolviendo con la inversa

