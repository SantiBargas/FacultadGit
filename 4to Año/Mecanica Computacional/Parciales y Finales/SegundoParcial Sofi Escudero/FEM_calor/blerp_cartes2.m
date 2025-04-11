function N = blerp_cartes2(nodos, xp, yp)
  % Determinar el tipo de elemento (triángulo o cuadrángulo)
  num_nodos = size(nodos, 1);

  if num_nodos == 4
    % Caso cuadrángulo (interpolación bilineal)
    x = nodos(:, 1);
    y = nodos(:, 2);

    % Coeficientes de las funciones de forma bilineales
    a = 0.25 * [1, 1, 1, 1]';
    b = 0.25 * [-1, 1, 1, -1]';
    c = 0.25 * [-1, -1, 1, 1]';
    d = 0.25 * [1, -1, 1, -1]';

    % Imprimir tabla para cuadrángulos
    printf("  [   a   |   b   |   c   |   d   ]\n");
    printf("-----------------------------------\n");
    for i = 1:4
      printf("  %8.4f | %8.4f | %8.4f | %8.4f\n", a(i), b(i), c(i), d(i));
    endfor
    printf("-----------------------------------\n");

    % Evaluar las funciones de forma en (xp, yp)
    xi = (2 * (xp - min(x)) / (max(x) - min(x))) - 1;
    eta = (2 * (yp - min(y)) / (max(y) - min(y))) - 1;
    N = a + b * xi + c * eta + d * xi * eta;

  elseif num_nodos == 3
    % Caso triangular
    A = det([ones(3, 1), nodos]) * 0.5; % Área del triángulo
    idx = [2, 3, 1]; % Índices cíclicos para los vértices

    % Coeficientes de las funciones de forma
    a = zeros(3, 1);
    b = zeros(3, 1);
    c = zeros(3, 1);

    for i = 1:3
      j = idx(i);
      k = idx(mod(i, 3) + 1);
      % Cálculo de coeficientes
      a(i) = nodos(j, 1) * nodos(k, 2) - nodos(k, 1) * nodos(j, 2);
      b(i) = nodos(j, 2) - nodos(k, 2);
      c(i) = nodos(k, 1) - nodos(j, 1);
    endfor

    % Dividimos por 2*A para normalizar
    a = a / (2 * A);
    b = b / (2 * A);
    c = c / (2 * A);

    % Imprimir tabla para triángulos
    printf("  [   a   |   b   |   c   ]\n");
    printf("---------------------------\n");
    for i = 1:3
      printf("  %8.4f | %8.4f | %8.4f\n", a(i), b(i), c(i));
    endfor
    printf("---------------------------\n");

    % Evaluar las funciones de forma en (xp, yp)
    N = a + b * xp + c * yp;

  else
    error("El número de nodos debe ser 3 (triángulo) o 4 (cuadrángulo).");
  endif
endfunction





