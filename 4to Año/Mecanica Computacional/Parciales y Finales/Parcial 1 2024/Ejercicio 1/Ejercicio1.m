
puntos = [-2 0 1];
k=1;
[coef] = taylorDF(puntos,k)

pkg load symbolic

% Definimos los puntos a usar (índices relativos)
puntos = [-2, 0, 1];  % T(i-2), T(i), T(i+1)

% Definimos las posiciones reales en la malla no uniforme
h = 0.25;  % Paso base
posiciones = [-h, 0, h/2];  % x_{i-2} = -h, x_i = 0, x_{i+1} = h/2

% Orden de la derivada
k = 1;  % Primera derivada

% Obtener coeficientes
coef = taylorDF_noUniforme(puntos, posiciones, k);

disp('Coeficientes obtenidos para la malla no uniforme:')
disp(coef)

