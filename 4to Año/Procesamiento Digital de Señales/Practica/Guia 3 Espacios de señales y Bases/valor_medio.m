function valor_medio = valor_medio(x)
    N = length(x); % Obtener la longitud de la señal
    valor_medio = (1 / (2 * N)) * sum(x); % Calcular el valor medio según la fórmula
end

##% Ejemplo de uso:
##% Supongamos que tienes un vector x que representa tu señal
##x = [0.5, 1, 1.5, 2, 1.5, 1, 0.5];
##valor_medio = calcular_valor_medio(x);
##disp("Valor medio de la señal:");
##disp(valor_medio);

