#PARAMETROS
k=2;
deltax=0.25;
nodos=5;
x=linspace(0,1,nodos);
G = @(x) 100 * (1 - x);
q=-1;

% Parámetros
nodos = 5;
x = linspace(0, 1, nodos); % Genera los valores de x en los nodos
G = @(x) 100 * (1 - x);    % Definición de la función G(x)

% Evaluación de G(x) en cada nodo y almacenamiento en un vector
G_values = arrayfun(G, x); % Evalúa G(x) en cada punto de x y almacena en G_values

% Mostrar los valores de G(x) en cada nodo
disp('Valores de G(x) en cada nodo:');
disp(G_values);

% Cálculo de F_values como G(x) * deltax^2 / k para cada nodo
F_values = (G_values * deltax^2) / k;
F_values(1)=10;
F_values(5)= ((G_values(5) * deltax^2)/k) + (2*deltax*q) / k;

F = F_values

A=[1 0 0 0 0 ; 1 -2 1 0 0 ; 0 1 -2 1 0 ; 0 0 1 -2 1 ; 0 0 0 1 -1];

% Resolución del sistema de ecuaciones A * T = F
T = A \ F; % Solución del sistema

% Mostrar los resultados
disp('Temperaturas en cada nodo:');
for i = 1:nodos
    fprintf('Nodo en x = %.2f -> T = %.4f\n', x(i), T(i));
end
