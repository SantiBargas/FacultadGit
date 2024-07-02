function S = PolinomioSpline(a, b, c, d, x)

n = length(a);
xd = x;
M = [d c b a]';
S = @(x) a(1)*(x == xd (1));

for i=1:n
 S = @(x) S(x) + ...
 polyval(M(i,:), (x - xd(i))).*(x>xd(i)).*(x<=xd(i+1));
end

##    a = a'; b = b'; c = c'; d = d';
##    n = length(xi) - 1; % N�mero de intervalos
##    S = zeros(size(x)); % Vector para almacenar los valores del polinomio S(x)
##
##    % Iterar sobre cada intervalo
##    for i = 1:n
##        idx = find(x >= xi(i) & x <= xi(i+1)); % �ndices de x en el intervalo actual
##        dx = x(idx)-xi(i); % Diferencia entre x y el inicio del intervalo
##
##        % Calcular el polinomio S(x) para el intervalo actual
##        S(idx) = a(i)+b(i)*dx+c(i)*dx.^2+d(i)*dx.^3;
##    end
end
