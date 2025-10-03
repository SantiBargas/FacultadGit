N = 100; % Tamaño de la ventana
n = (0:N-1)';
hamming_window = 0.54 - 0.46 * cos(2*pi*n / (N-1));

% Calcular la transformada de Fourier de la ventana de Hamming
fft_hamming = fft(hamming_window);

% Calcular el espectro de frecuencia (magnitud)
magnitude_spectrum = abs(fft_hamming);

% Obtener las frecuencias correspondientes
fs = 1000; % Frecuencia de muestreo
frequencies = (0:N-1) * fs / N;

% Graficar el espectro de frecuencia (escala logarítmica en el eje y)
figure;
plot(frequencies, magnitude_spectrum);
title('Espectro de la Ventana de Hamming');
xlabel('Frecuencia (Hz)');
ylabel('Magnitud');
set(gca, 'YScale', 'log'); % Usar escala logarítmica en el eje y

