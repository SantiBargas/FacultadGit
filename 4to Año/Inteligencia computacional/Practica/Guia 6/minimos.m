% Definir la función
f = @(x) -x .* sin(sqrt(abs(x)));

% Definir el intervalo
x_min = -512;
x_max = 512;

% Encontrar el mínimo
[x_min_value, f_min_value] = fminbnd(f, x_min, x_max);

% Mostrar resultados
fprintf('El valor de x que minimiza la función es: %f\n', x_min_value);
fprintf('El valor mínimo de la función es: %f\n', f_min_value);
disp('')
disp('')
####################################################
##################################################
############################################################

% Definir la función
f = @(x, y) (x.^2 + y.^2).^0.25 .* (sin(50*(x.^2 + y.^2).^0.1).^2 + 1);

% Definir el intervalo
x_min = -100;
x_max = 100;
y_min = -100;
y_max = 100;

% Crear una grilla de puntos en el intervalo
[x, y] = meshgrid(linspace(x_min, x_max, 1000), linspace(y_min, y_max, 1000));

% Evaluar la función en esos puntos
f_values = f(x, y);

% Encontrar el mínimo
[min_value, idx] = min(f_values(:));

% Obtener los valores de x y y correspondientes al mínimo
[x_min_value, y_min_value] = ind2sub(size(f_values), idx);

% Mostrar resultados
fprintf('El valor de x que minimiza la función es: %f\n', x(x_min_value, y_min_value));
fprintf('El valor de y que minimiza la función es: %f\n', y(x_min_value, y_min_value));
fprintf('El valor mínimo de la función es: %f\n', min_value);

