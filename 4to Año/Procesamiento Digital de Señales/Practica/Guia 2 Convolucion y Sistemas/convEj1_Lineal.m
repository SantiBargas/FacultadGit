function y = convEj1_Lineal(x,h)
% Basado pag 127
% Dimensión inicial
xSize = length(x); % 5
hSize = length(h); % 3
N = xSize + hSize - 1; % 7
% Ceros a concatenar para que nos
% de xSize + hSize -1 convoluciones  Esto asegura que se puedan realizar todas las convoluciones necesarias sin salirse de los límites.
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

% Parte 2: Comparación con conv y filter

y_conv = conv(x, h); #Conv de octave
% Usar la función filter de Octave
A = 1; % Coeficientes de retroalimentación
B = h; % Coeficientes de alimentación directa
y_filter = filter(B, A, x);

disp("Resultado de convLineal:");
disp(y);
disp("Resultado de conv:");
disp(y_conv);
disp("Resultado de filter:");
disp(y_filter);

end


% Definir señales de entrada x y filtro h
##x = [1, 2, 3, 4, 5];
##h = [0.5, 1, 0.5];
##y = convEj1_Lineal(x,h);

#CONVOLUCION: Operacion matematica que combina dos funciones para
#producir una tercera funcion que representa como una de las funciones influye
#en la otra cuando se superponen y se desplazan a lo largo del eje
