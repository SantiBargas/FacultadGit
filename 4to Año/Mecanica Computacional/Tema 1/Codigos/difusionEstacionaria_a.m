function u = difusionEstacionaria_a(K0, Q, a, b, L, n)
    % Parámetros de entrada:
    % K0: Coeficiente de conductividad
    % Q: Función de fuente de calor (puede ser una función handle de x)
    % a: Valor de contorno en x = 0
    % b: Valor de contorno en x = L
    % L: Longitud del dominio
    % n: Número de divisiones del dominio

    % Discretización del dominio
    h = L / (n + 1);    % Paso del intervalo
    x = linspace(0, L, n + 2); % Puntos de discretización, incluyendo los de contorno

    % Inicialización del vector de solución
    u = zeros(n + 2, 1);

    % Asignación de las condiciones de contorno
    u(1) = a;
    u(end) = b;

    % Construcción de la matriz del sistema
    A = zeros(n, n);
    b_vec = zeros(n, 1);

    for i = 1:n
        xi = x(i + 1); % punto interior actual
        A(i, i) = 2 * K0 / h^2;
        if i > 1
            A(i, i - 1) = -K0 / h^2;
        end
        if i < n
            A(i, i + 1) = -K0 / h^2;
        end

        % Fuente de calor evaluada en el punto xi
        b_vec(i) = Q(xi);
    end

     % Imprimir la matriz A
    disp('Matriz A:');
    disp(A);

    % Ajuste del vector del lado derecho con condiciones de contorno
    b_vec(1) = b_vec(1) + K0 * a / h^2;
    b_vec(end) = b_vec(end) + K0 * b / h^2;

    % Resolución del sistema lineal
    u(2:end-1) = A \ b_vec;
end


##K0 = 1;
##Q = @(x) x;
##a = 0;
##b = 1;
##L = 1;
##n = 10;

##u = difusionEstacionaria_a(K0, Q, a, b, L, n);
##disp(u);*/

