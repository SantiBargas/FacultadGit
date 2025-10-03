function potencia_media = potencia_media(x)
    N = length(x); % Obtener la longitud de la señal
    suma = sum(abs(x).^2); % Calcular la suma de los cuadrados de los valores absolutos de la señal
    potencia_media = (1 / (2 * N)) * suma; % Calcular la potencia media según la fórmula
end

##% Ejemplo de uso:
##% vector x que representa una señal
##x = [0.5, 1, 1.5, 2, 1.5, 1, 0.5];
##potencia_media = calcular_potencia_media(x);
##disp("Potencia media de la señal:");
##disp(potencia_media);

