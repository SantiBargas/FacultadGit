function expansion_matrix = taylor_expansion(displacements, max_order)
    pkg load symbolic
    warning('off', 'all'); % Silenciar advertencias innecesarias
    syms h % h simbólico para poder reemplazarlo más tarde

    % Inicializar la matriz de expansiones de Taylor como celdas
    expansion_matrix = cell(length(displacements), max_order + 1);

    % Iterar sobre cada desplazamiento
    for i = 1:length(displacements)
        % Desplazamiento actual
        disp = displacements(i);

        % Calcular términos de la serie de Taylor
        for n = 0:max_order
            if n == 0
                % Primer término: phi(x + disp * h)
                expansion_matrix{i, n + 1} = sprintf('Φ_i', disp);
            else
                % Crear los términos del desarrollo de Taylor
                 coeficiente = sprintf('%d^%d/%d', disp, n, factorial(n));   % Coeficiente como texto
                potencia_h = sprintf('%s^%d', char(h), n);      % Potencia de h simbólica como texto
                derivada = sprintf('∂^%d(Φ)/dx^%d', n, n);     % Derivada como texto

                % Combinar todo en un término legible
                expansion_matrix{i, n + 1} = sprintf('%s * %s * %s', coeficiente, potencia_h, derivada);
            end
        end
    end
end

