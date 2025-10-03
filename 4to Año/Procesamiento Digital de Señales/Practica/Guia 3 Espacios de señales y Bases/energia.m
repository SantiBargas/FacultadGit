function energia = energia(x)
    energia = norm(x, 2)^2; % Calcular la norma l2 y elevarla al cuadrado
end

##% Ejemplo de uso:
##% Supongamos que tienes un vector x que representa tu señal
##x = [0.5, 1, 1.5, 2, 1.5, 1, 0.5];
##energia = calcular_energia(x);
##disp("Energía de la señal:");
##disp(energia);

