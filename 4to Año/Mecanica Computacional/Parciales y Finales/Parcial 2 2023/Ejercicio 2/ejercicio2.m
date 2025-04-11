% Definir las matrices de rigidez elementales
Ke1 = [-2  2;
        2 -2];

Ke2 = [ 14/3  -16/3   2/3;
       -16/3 32/3  -16/3;
        2/3  -16/3   14/3];

% Definir los vectores de fuerza elementales
Fe1 = [-2; -0.5];
Fe2 = [-0.166; 4/3; 4/3];

% Inicializar matriz global 4x4 y vector global 4x1
Kg = zeros(4,4);
Fg = zeros(4,1);

% Ensamblaje de la matriz global
Kg(1:2,1:2) += Ke1;    % Ensambla Ke1 en posiciones correspondientes
Kg(2:4,2:4) += Ke2;    % Ensambla Ke2 en posiciones correspondientes

% Ensamblaje del vector de fuerzas global
Fg(1:2) += Fe1;        % Ensambla Fe1
Fg(2:4) += Fe2;        % Ensambla Fe2

% Aplicación de la condición de contorno T1 = 0 en x = -1
Kg(1,:) = 0;  % Se anula la primera fila
Kg(:,1) = 0;  % Se anula la primera columna
Kg(1,1) = 1;  % Se pone 1 en la diagonal para la condición esencial
Fg(1) = 0;    % Se fuerza el valor de T1 a 0

% Aplicación de la condición de Robin en x = 1
h = 5;           % Coeficiente de transferencia de calor
T_inf = 50;      % Temperatura ambiente

Kg(4,4) += h;    % Modificar la matriz global
Fg(4) += h * T_inf;  % Modificar el vector de fuerzas

% Mostrar matrices resultantes
disp("Matriz de rigidez global Kg:");
disp(Kg);

disp("Vector de fuerzas global Fg:");
disp(Fg);

% Resolver el sistema de ecuaciones
T = Kg \ Fg;
disp("Temperaturas en los nodos:");
disp(T);


% Coordenada donde queremos evaluar la temperatura
x_eval = 0.25;

% Funciones de forma cuadráticas evaluadas en x=0.25
N1 = 2 * (1 - x_eval) * (0.5 - x_eval);
N2 = 4 * x_eval * (1 - x_eval);
N3 = 2 * x_eval * (x_eval - 0.5);

% Temperaturas nodales obtenidas del sistema
T2 = T(2);
T3 = T(3);
T4 = T(4);

% Evaluación de la temperatura en x=0.25
T_x_eval = N1 * T2 + N2 * T3 + N3 * T4;

% Mostrar resultado
fprintf("Temperatura en x=%.2f: %.4f\n", x_eval, T_x_eval);
