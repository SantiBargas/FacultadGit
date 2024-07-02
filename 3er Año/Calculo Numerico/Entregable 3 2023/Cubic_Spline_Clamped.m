function[a, b, c, d] = Cubic_Spline_Clamped(x,y,dy0,dyn)
  # Pasamos un arreglo de puntos x e y
  # Es una funcion para el calculo de una Spline Cubica sujeta, es decir con 
  # derialphaadas primeras dadas en los extremos (dy0 y dyn)
  # programado en base a Burden Edición 10 pag 115.
  # S(x) = Sj(x) = aj + bj(x-xj) + cj(x-xj)^2 + dj(x-xj)^3 para xj <= x <= xj+1;
  # S'(x1) = dy0  , S'(xn+1)=dyn

  % Medimos la longitud de los datos
  n = length(x);
  alpha = zeros(n,1);
  
  % Paso 1: Calculamos los h de cada Spline.
  h(1:n-1) = x(2:n)-x(1:n-1);

  % Paso 2 y 3: Calcula los terminos independientes (alpha)
  alpha(1) = 3*((y(2)-y(1))/h(1)-dy0);
  alpha(2:n-1) = 3*((y(3:n)-y(2:n-1))./h(2:n-1)-(y(2:n-1)-y(1:n-2))./h(1:n-2));
  alpha(n) = 3*(dyn-(y(n)-y(n-1))/h(n-1));

# de aca en adelante resolalphaemos un sistema lineal tridiagonal utilizando un método
# que alphaimos en Métodos Directos, Crout optimizado para matrices tridiagonales.
# acordarse que tenemos base 1.

  % Paso 4:
  l(1) = 2*h(1); 
  u(1) = 0.5;
  z(1) = alpha(1)/l(1);

  % Paso 5:
  for i = 2:n-1
    l(i) = 2 * ( x(i+1)-x(i-1) ) - h(i-1) * u(i-1);
    u(i) = h(i) / l(i);
    z(i) = (alpha(i) - h(i-1) * z(i-1) ) / l(i);
  endfor

  %Paso 6:
  l(n) = h(n-1) * (2-u(n-1));
  z(n) = (alpha(n) - h(n-1)*z(n-1) ) / l(n);
  c(n) = z(n);

  % Paso 7:
  for i = n-1:-1:1
    c(i) = z(i) - u(i) * c(i+1);
    b(i) = (y(i+1)-y(i))/ h(i) - h(i) * ( c(i+1) + 2 * c(i) ) / 3;
    d(i) = (c(i+1)-c(i))/(3*h(i));
  endfor
  
  a = y(1:n-1);
  b = b';
  c = c(1:n-1)';
  d = d';
endfunction