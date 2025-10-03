function y = convCircular(x,h)
% Dimensión inicial
N = length(x);
y = zeros(1,N);

% fila
for k=1:N
    % columna
    for l=1:length(h)
        % suma
        % el modulo puede ser replicado
        % repitiendo el x varias veces
        a=mod((N+k-l),N)+1;
        y(k) = y(k) +  h(l) * x(a);
    end
end

end
##x = [1, 2, 3, 4, 5];
##h = [0.5, 1, 0.5];
##y = convCircular(x, h);
##disp(y);
