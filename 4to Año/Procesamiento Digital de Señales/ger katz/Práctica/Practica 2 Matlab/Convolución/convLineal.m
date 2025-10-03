function y = convLineal(x,h)
% Basado pag 127
% Dimensión inicial
xSize = length(x); % 5
hSize = length(h); % 3
N = xSize + hSize - 1; % 7 
% Ceros a concatenar para que nos 
% de xSize + hSize -1 convoluciones
x = [x zeros(1,N-xSize)];  % 5 5 5 5 5   0 0        =>  N = 7
h = [h zeros(1,N-hSize)];  % 3 3 3       0 0 0 0    =>  N = 7
% Redimenciono
y = zeros(1,N);

% fila
for i=1:N
    k=i;
    % columna
    for j=1:i
        % suma
        y(i) = y(i) +  h(j) * x(k);
        k = k-1;
    end
end
end

% Parte 2 
% B = H o X (es indistinto)
% A = [1, 0, 0, 0] asi no toma el a2 y eso
% X = X o H (indistinto)

% x = [2 2];
% h = [1 1 -1];