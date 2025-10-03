function y = convCircular2(x,h)
% Dimensión inicial
xSize = length(x); 
y = zeros(1,xSize);

% fila
for k=1:xSize
    % columna
    a = k;
    for l=1:xSize
        % suma
        y(k) = y(k) +  h(l) * x(a);
        a = a - 1;
        if a == 0
            a = xSize;
        end
    end
end
end

% MILTON ©