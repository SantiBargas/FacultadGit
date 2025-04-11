function [coef] = taylorDF_noUniforme(puntos, posiciones, k)
    pkg load symbolic
    if length(puntos) ~= length(posiciones)
        error('Los vectores de puntos y posiciones deben tener la misma longitud');
    end

    syms x;
    N = length(puntos);
    M = zeros(N);

    % Construimos la matriz de Taylor con distancias reales
    for i = 1:N
        M(i,:) = (posiciones - x).^(i-1) ./ factorial(i-1);
    end

    % Vector b para la derivada de orden k
    b = zeros(N,1);
    b(k+1) = 1;  % El término de la derivada de orden k se iguala a 1

    % Resolver el sistema
    coef = M\b;
end

