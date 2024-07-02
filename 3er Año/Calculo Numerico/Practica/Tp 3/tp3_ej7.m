n = 1000; % número de filas
A = zeros(n, n); % Crear una matriz de n x 2 de ceros

for i = 1:n
  for j = 1:n

      if (j == i)
        A(i,j) = 2*i
      elseif (j == i+2 || j == i-2)
        A(i,j) = 0.5*i
      elseif (j == i+4 || j == i-4)
        A(i,j) = 0.25*i
      else
        A(i,j) = 0
      endif

  endfor
endfor
