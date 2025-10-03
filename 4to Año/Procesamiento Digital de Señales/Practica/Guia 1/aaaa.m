% Parámetros de entrada
tini = 0;
tfin = 1;
fm = 10; % Frecuencia de muestreo original (Hz)
fs = 0.5; % Frecuencia de la función sinc (Hz)

% Generación de la señal discreta original
[T, sinc] = ej1_b_sync(tini, tfin, fm, fs);

% Nuevo período de muestreo para la señal sobremuestreada (fm*4)
Ti=(1/fm*4);

% Vector de tiempo para la señal sobremuestreada
ti = tini:Ti:tfin-Ti;

% Interpolación utilizando la función sinc
xi = zeros(size(ti));
for m = 1:length(ti)
    for n = 1:length(T)
       xi(m) = xi(m) + sinc(n) * sinc_interp((ti(m) - T(n)) / T); % Utilizando directamente la función sinc
    end
end

% Graficación de las señales
subplot(2,1,1);
stem(T, sinc, 'b', 'LineWidth', 1.5); % Señal original
title('Señal Original');
xlabel('Tiempo (s)');
ylabel('Amplitud');
grid on;

subplot(2,1,2);
stem(ti, xi, 'r', 'LineWidth', 1.5); % Señal sobremuestreada e interpolada
title('Señal Sobremuestreada e Interpolada');
xlabel('Tiempo (s)');
ylabel('Amplitud');
grid on;
