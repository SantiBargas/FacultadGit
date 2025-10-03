function y = convCircular(x,h)
% Dimensión inicial
xSize = length(x); 
y = zeros(1,xSize);

% fila
for k=1:xSize
    % columna
    for l=1:xSize
        % suma
        % el modulo puede ser replicado
        % repitiendo el x varias veces
        a=mod((xSize+k-l),xSize)+1;
        y(k) = y(k) +  h(l) * x(a);
    end
end
end

% MILTON ©