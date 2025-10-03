##################################################################################
A = 1; % Constante A
f = 1; % Frecuencia en Hz
T = 1/f; % Periodo de muestreo
n = 0:10; % Rango de valores de n
w = 2 * pi * f;
g = A * sin(w * n * T);
% Definición de la entrada x[n] (por ejemplo, un impulso unitario)
x = [0 0 0  1 1 zeros(1, length(n)-5)]
% Calculo de la salida y[n]
y = g .* x;
figure;
% Graficar x[n]
subplot(2, 1, 1);
stem(n, x, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('x[n]');
title('Entrada x[n]');

% Graficar y[n]
subplot(2, 1, 2);
stem(n, y, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('y[n]');
title('Salida del sistema y[n] para la entrada x[n] = \delta[n]');

#############y[n]=∑desde(k=n−n0) hasta(n+n0)de x[k]################################

n = -10:10; #rango de valores de n
n0 = 5; #parámetro n0 (el ancho del rango)
% Definir la entrada x[n] (por ejemplo, un impulso unitario)
x = [ones(1, length(n))]; % Impulso unitario

for i = 1:length(n)
    lim_inf = max(i-n0, 1); % Límite inferior del rango
    lim_sup = min(i+n0, length(x)); % Límite superior del rango
    y(i) = sum(x(lim_inf:lim_sup)); % Sumar los valores de x[k] en el rango
end

% Graficar la salida y[n]
figure;
subplot(2, 1, 1);
stem(n, x, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('x[n]');
title('Impulso unitario');

subplot(2, 1, 2);
stem(n, y, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('y[n]');
title('Salida del sistema y[n] = n*x[n] para la entrada x[n] = \delta[n]');



#############   y[n]=x[n]+2  ################################

n = -10:10; #rango de valores de n
x = [ones(1, length(n))]; % Impulso unitario
y = x + 2;
% Graficar la salida y[n]
figure

subplot(2,1,1);
stem(n, x, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('x[n]');
title('Impulso unitario');

subplot(2,1,2);
stem(n, y, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('y[n]');
title('Salida del sistema y[n] = n*x[n] para la entrada x[n] = \delta[n]');


#############   y[n]=n*x[n]  ################################

% Definir el rango de valores de n
n = -10:10;

% Definir la entrada x[n] (por ejemplo, un impulso unitario)
x = [ones(1, length(n))]; % Impulso unitario

% Calcular la salida y[n]
#y = n .* x;
for i = 1:length(n)
    y(i) = n(i) * x(i); % Multiplicar n por x para cada valor de n
end

% Graficar la salida y[n] en un subplot
figure;

subplot(2, 1, 1);
stem(n, x, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('x[n]');
title('Impulso unitario');

subplot(2, 1, 2);
stem(n, y, 'filled', 'LineWidth', 1.5);
xlabel('n');
ylabel('y[n]');
title('Salida del sistema y[n] = n*x[n] para la entrada x[n] = \delta[n]');




