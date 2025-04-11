function [T_ap] = solOrden1(h)
  k = 1;
  x = 1:h:5;
  n = length(x);
  G = 100 * ((x(1:n-1) - 3).^2);
  K = zeros(n);
  b = zeros(n, 1);

  fila = [1 -2 1];
  for i = 2:(n-1)
    K(i, i-1:i+1) = fila;
  end

  K(1, 1:2) = [-1 1];
  K(n, n) = 1;

  b(1:n-1) = (-G./k) * (h^2);
  b(1) = 2*h;

  T_ap = K\b;
end

