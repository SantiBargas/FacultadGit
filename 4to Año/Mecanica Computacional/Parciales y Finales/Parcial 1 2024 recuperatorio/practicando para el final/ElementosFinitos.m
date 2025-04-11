pkg load symbolic
warning('off', 'all');
# Parámetros de entrada
x1=0;
x2=0.5;
h=0.1
xnode = x1:h:x2; % Discretización
k = 25; % Valor de rigidez

# Definimos un vector de funciones de carga para cada barra
##G = { @(x) 100 * (4 - x);  @(x) 100 * (4 - x); @(x) 100 * (4 - x); @(x) 100 * (4 - x) }; % Ejemplo de funciones
##G_index=1 #Depende de x


G = { 0;0;0;0;3000 };
G_index=0 #No depende de x


# Inicializar matrices y vectores
n_nodos = length(xnode);
K = zeros(n_nodos, n_nodos);
M = zeros(n_nodos, n_nodos);
F = zeros(n_nodos, 1);

# Definir variable simbólica
syms x;

# Calcular matrices de elementos
K_el = ((-k)/h) * [1 -1; -1 1] % Matriz de rigidez del elemento
M_el = (h / 6) * [2 1; 1 2] % Matriz de masa del elemento

% Inicializar el vector de fuerzas
F_e = zeros(length(xnode)-1,2); % Cada columna corresponderá a un elemento

### Definir funciones de forma como vectores y calcular integrales
for i = 1:(length(xnode)-1)
    x1 = xnode(i)
    x2 = xnode(i + 1)

    % Funciones de forma
    N = [(x2 - x) / h; (x - x1) / h] % N para el elemento

  % Calcular las integrales y almacenarlas en el vector F_e

  #G DEPENDE DE x
    if G_index==1
      F_e(i,1) = double(int(G{i}(x) * N(1), x, x1, x2));
      F_e(i,2) = double(int(G{i}(x) * N(2), x, x1, x2));
    endif

  #G NO DEPENDE DE x
    if G_index==0
        F_e(i,1) = double(int(G(i) * N(1), x, x1, x2))
        F_e(i,2) = double(int(G(i) * N(2), x, x1, x2))
    endif
end

###############ENSANBLAMOS#############################################
#######################################################################
K_global = zeros(n_nodos,n_nodos);
% Ensamblar la matriz de rigidez global K
for i = 1:(length(xnode)-1)
    K_global(i:i+1, i:i+1) += K_el; % Sumar la matriz de rigidez del elemento a la matriz global
end

% Inicializar el vector de fuerzas global
F_global = zeros(n_nodos, 1);
% Ensamblar el vector de fuerzas
for i = 1:(length(xnode)-1)
    F_global(i:i+1) += F_e(i, :)'; % Sumar las fuerzas del elemento al vector global
end

M_global = zeros(n_nodos,n_nodos);
% Ensamblar la matriz de masa global M
for i = 1:(length(xnode)-1)
    M_global(i:i+1, i:i+1) += M_el; % Sumar la matriz de masa del elemento a la matriz global
end

disp('K global sin condiciones de contorno')
K_global
disp('F global sin condiciones de contorno')
F_global
disp('Matriz de masa global M:');
M_global

#############################################
##### Condiciones de frontera################
#############################################

K_global(6,:) = 0;  % Condición Dirichlet
K_global(6,6) = 1; % Condición Dirichlet
F_global(6) = 100;  % Temperatura en el nodo x=0.5 T=100
F_global(1) += -12.5; % Condición Neumann

#############################################
########### IMPRIMIR STENCIL ################
#############################################

disp('K global con condiciones de contorno')
K_global
disp('F global con condiciones de contorno')
F_global
disp('Matriz de masa global M:');
M_global

# Resolver el sistema K * T = F
T = K_global \ F_global;
disp('Solución T:');
disp(T);

##
###############################################
############# INCISO B) RECU PARCIAL 1 2024 ################
###############################################
##

%%VALOR DE LA TEMPERATURA EN X=0.25
N1 = (0.3 - 0.25)/0.1 ;
N2 = (0.25 - 0.2)/0.1 ;
T_25 = N1*T(3) + N2*T(4)

%%VALOR DEL FLUJO EN X=0.25
q_25 = -k * (T(4) - T(3))/0.1

##
###############################################
############# INCISO C) RECU PARCIAL 1 2024 ################
###############################################
##

%%Como solo da informacion de T2 T3 Y T4 Reducimos Kglobal y Fglobal a esos nodos correspondientes
rho_cp = 1;     % Producto de densidad por calor específico
dt = 0.05;      % Paso de tiempo

% Condiciones iniciales
T_n = [63.5; 67.5; 74.5];  % Temperaturas iniciales en nodos 2, 3 y 4

% Extraer submatrices para T2, T3 y T4
K_c = K_global(2:4, 2:4);   % Submatriz reducida de K para los nodos 2, 3 y 4
F_c = F_global(2:4);        % Subvector reducido de F para los nodos 2, 3 y 4

% Construir la matriz A y el vector b para el esquema implícito
I = eye(3);  % Matriz identidad para los nodos reducidos

A = (rho_cp / dt) * I + K_c;  % Matriz del sistema
b = F_c + (rho_cp / dt) * T_n;  % Vector del sistema

% Resolver para T_{n+1}
T_n1 = A \ b;

% Mostrar resultados
disp('Matriz reducida K_c:');
disp(K_c);
disp('Vector reducido F_c:');
disp(F_c);
disp('Temperaturas en el siguiente paso de tiempo (T_n+1):');
disp(T_n1);
