pkg load symbolic

# Parámetros de entrada
x1=0;
x2=0.5;
h=0.1;
rho = 1;
cp= 1;
xnode = x1:h:x2 % Discretización
k = 25; % Valor de rigidez
G = 30; % Función de carga
G_index = 30;

# Inicializar matrices y vectores
n_nodos = length(xnode)
K = zeros(n_nodos, n_nodos);
M = zeros(n_nodos, n_nodos);
F = zeros(n_nodos, 1);

# Definir variable simbólica
syms x;

# Calcular matrices de elementos
K_el = ((-k)/h) * [1 -1; -1 1] % Matriz de rigidez del elemento
M_el = rho*cp*(h / 6) * [2 1; 1 2] % Matriz de masa del elemento

% Inicializar el vector de fuerzas
F_e = zeros(length(xnode)-1,2); % Cada columna corresponderá a un elemento

### Definir funciones de forma como vectores y calcular integrales
for i = 1:(length(xnode)-1)
    x1 = xnode(i)
    x2 = xnode(i + 1)

    % Funciones de forma
    N = [(x2 - x) / h; (x - x1) / h] % N para el elemento

  #G DEPENDE DE x
    if G_index==1
      F_e(i,1) = double(int(G(x) * N(1), x, x1, x2));
      F_e(i,2) = double(int(G(x) * N(2), x, x1, x2));
    endif

  #G NO DEPENDE DE x
    if G_index==0
        F_e(i,1) = double(int(G * N(1), x, x1, x2))
        F_e(i,2) = double(int(G * N(2), x, x1, x2))
    endif

end

#######################################################################
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

M_global = zeros(n_nodos,n_nodos)
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

F_global = [0;0;0;0;3;1.5];


% Aplicar la condición de frontera en el nodo derecho (Dirichlet T6 = 100)
K_global(6,:) = 0;
K_global(:,6) = 0;
K_global(6,6) = 1
F_global(6) = 100;

delta_t = 0.1;

q = -12.5; % Valor de la condición de Neumann (flujo de calor en el nodo izquierdo)
F_global(1) += q % Aplicar la condición de Neumann en el nodo izquierdo

# Resolver el sistema para obtener las temperaturas en cada nodo
T = K_global \ F_global;

T2=63.5;
T3=67.5;
T4=74.5;


#T_n_mas_1_nodo3 = inv(M_global)(3, :) * ((delta_t / (rho * cp)) * (F_global - K_global * T) + M_global * T)
# Parámetros
delta_t = 0.05;  % Tiempo de paso
rho = 1;  % Densidad
cp = 1;  % Calor específico

# Valores de T en el tiempo actual (T^n)
T_actual = [0; T2; T3_actual; T4; 0; 0]; % Vector completo de 6 elementos

# Calcular T_3 en el siguiente paso de tiempo
T_n_mas_1_nodo_3 = inv(M_global(3,3)) * ((delta_t / (rho * cp)) * (F_global(3) - K_global(3,:) * T_actual) + M_global(3,:) * T_actual)
### TEMPERATURA EN x=3.2 interpolacion directa
#####seleccionamos los nodos 3 y 4 ya que son los que estan entre 3.2
##T3 = T(3)
##T4=T(4)
##
### Calcular T en x = 3.2 mediante interpolación lineal
##x_eval = 0.025;
##T_x025 = T3 + (x_eval - 0.03) / (0.03 - 0.02) * (T4 - T3);
##
### Mostrar el resultado
##disp('Temperatura en x = 3.2 mediante interpolación lineal directa:')
##disp(T_x025)
##
### Interpolación usando funciones de forma
##syms x;
##
### Funciones de forma asociadas a T_3 y T_4
##T3 = T(3)
##T4=T(4)
##N1 = (0.04 - x) / (0.04 - 0.03);  % Función de forma asociada a T_3
##N2 = (x - 0.03) / (0.04 - 0.03);   % Función de forma asociada a T_4
##
### Evaluar las funciones de forma en x = 0.025
##x_eval = 0.025;
##N_eval = double(subs([N1; N2], x, x_eval));
##
### Calcular T en x = 0.025 usando funciones de forma
##T_x0_025 = N_eval' * [T3; T4];
##
### Mostrar el resultado
##disp('Temperatura en x = 0.025 usando funciones de forma:')
##disp(T_x0_025)
##
##
### Parámetros de entrada
##k = 2;  # Conductividad térmica (valor dado en el problema)
##
### Definir las temperaturas en los nodos 3 y 4
##T3 = T(3)
##T4=T(4)
##dT_dx = (T4 - T3) / (0.1) # Calcular el gradiente de temperatura entre x = 3 y x = 3.5
##
### Calcular el flujo de calor en x = 3.2 usando la ley de Fourier
##q_x3_2 = -k * dT_dx;
##q= -k * (T(4) - T(3)) / 0.1
##
### Mostrar el resultado
##disp('Flujo de calor en x = 3.2:')
##disp(q_x3_2)
##

#############################################
########### IMPRIMIR STENCIL ################
#############################################

##disp('K global con condiciones de contorno')
##K_global
##disp('F global con condiciones de contorno')
##F_global
##disp('Matriz de masa global M:');
##M_global
##
###############################################
############# INCISO B) PARCIAL 1 2024 ################
###############################################
##
##T = [10; 39.848; 52.149; 54.173; 52.852]; % Condiciones iniciales
##rho = 1;
##cp= 1;
##delta_t = 0.1; % Paso de tiempo
##
###### Cálculo de T_n_mas_1
### Para esquema implícito: (M + delta_t * K) * Tn+1 = M*T^n + delta_t * F
##T_n_mas_1 = inv(M_global) * ( (delta_t)/(rho*cp) * (F_global-(K_global*T))+ M_global*T)
##T_n_mas_1 = inv(M_global) * ((delta_t / (rho * cp)) * (F_global - K_global * T) + M_global * T)
##
##### Calculo de T_n_mas_1
### Para esquema explicito
##T_n_mas_1 = T + inv(M_global)*( (delta_t / (rho * cp)) * (K_global * T+ F_global))




