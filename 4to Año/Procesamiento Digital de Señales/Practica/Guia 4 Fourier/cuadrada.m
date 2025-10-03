function [t, y] = cuadrada(fm)
    tm = 1 / fm; % Periodo de la señal
    t = -1 : tm : 1 - tm; % Vector de tiempo

    % Generar la señal cuadrada
    y = -1 * (t < 0) + 1 * (t >= 0);
end

