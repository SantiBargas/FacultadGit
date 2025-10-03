%PAG 93

% Definir el tamaño de las ventanas
N = 100; % Número de muestras

w = ventana_hammging(-0.5,0.5)


% Graficar las ventanas
figure;
plot(rect_window);
title('Ventana Rectangular');
figure
plot(hanning_window);
title('Ventana de Hanning');
figure;
plot(hamming_window);
title('Ventana de Hamming');
figure;
plot(bartlett_window);
title('Ventana de Bartlett (Triangular)');
figure;
plot(blackman_window);
title('Ventana de Blackman');

