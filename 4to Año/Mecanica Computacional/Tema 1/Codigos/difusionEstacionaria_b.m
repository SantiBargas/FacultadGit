 function u = difusionEstacionaria_b(K0, Q, a, b, L, n)

    % Parámetros de entrada:
    % K0: Coeficiente de conductividad
    % Q: Función de fuente de calor (puede ser una función handle de x)
    % a: Valor de contorno en x = 0
    % b: Valor de contorno en x = L
    % L: Longitud del dominio
    % n: Número de divisiones del dominio

    h= L / (n); %paso del intervalo
    x = linspace(0,L,n+2);
    print(x)

    u=zeros(n+2 , 1) #vector de zeros de n+2 de 1 columna
    print(u)

    u(1) = a;
    A = zeros(n+1 , n+1);
    b_vec = zeros(n+1,1);

    for i = 1:n
        xi = x(i+1);
        A(i , i) = 2*K0 / h^2;
        if i > 1
            A(i,i-1) = -K0 / h^2;
        end
        if i < n
            A(i,i+1) = -K0 / h^2;
        end
        b_vec(i) = Q(xi);

    endfor
% Ajuste para la condición de contorno Dirichlet en x = 0
    b_vec(1) += K0 * a / h^2;

    % Ajuste para la condición de contorno de Robin en x = L
    A(n+1, n) = -K0 / h;
    A(n+1, n+1) = K0 / h + H2;
    b_vec(n+1) = H2 * ue;

    % Imprimir la matriz A
    disp('Matriz A:');
    disp(A);

    % Resolver el sistema
    u(2:end) = A \ b_vec;
 endfunction



