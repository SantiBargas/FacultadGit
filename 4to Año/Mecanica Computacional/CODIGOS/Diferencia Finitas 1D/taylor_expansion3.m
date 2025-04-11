% Función de expansión de Taylor
function expansion_matrix = taylor_expansion(displacements, max_order)
    pkg load symbolic
    syms h phi % Declaramos h y phi como simbólicos

    % Inicializar la matriz de expansiones de Taylor como celdas
    expansion_matrix = cell(length(displacements), max_order + 1);

    % Iterar sobre cada desplazamiento
    for i = 1:length(displacements)
        % Desplazamiento actual
        disp = displacements(i);

        % Calcular términos de la serie de Taylor
        for n = 0:max_order
            if n == 0
                % Primer término: phi
                expansion_matrix{i, n + 1} = phi; % Término base sin derivadas
            else
                % Crear los términos del desarrollo de Taylor
                coeficiente = disp^n / factorial(n); % Coeficiente numérico
                potencia_h = h^n;                  % Potencia de h

                % Combinar todo en un término legible
                expansion_matrix{i, n + 1} = coeficiente * potencia_h;
            end
        end
    end
end

% Parámetros para la prueba
displacements = [1]; % Solo phi_{i+1}
max_order = 3;       % Hasta el tercer orden

% Ejecutar la función
expansion = taylor_expansion(displacements, max_order);

% Mostrar resultados para phi_{i+1}
fprintf('Expansión de Taylor para phi_{i+1}:\n');
for n = 0:max_order
    fprintf('Término de orden %d: %s\n', n, char(expansion{1, n + 1}));
end


