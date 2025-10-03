% Definir parámetros
Fs = 1000; % Frecuencia de muestreo
t = 0:1/Fs:1-1/Fs; % Vector de tiempo de 0 a 1 segundo con paso de 1/Fs

% Generar señal de rampa
rampa = t;

% Graficar la señal de rampa
figure;
plot(t, rampa, 'LineWidth', 2);
title('Señal de Rampa');
xlabel('Tiempo (s)');
ylabel('Amplitud');
grid on;

