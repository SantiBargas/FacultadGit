function [P, L] = Lagrange_grafica(x,y)
  n = length(x);
  L = zeros(n,n);
  P = zeros(1,n);

  % FORMACI�N DE LOS COEF. Li DE LAGRANGE
  for i = 1:n
    V = 1;
    for j = 1:n
      if i~=j
        V = conv(V,poly(x(j)))/(x(i)-x(j));
      endif
    endfor
    L(i,:) = V;
  % C�LCULO DE LOS COEFICIENTES DEL POLINOMIO INTERPOLADOR
    P = P + y(i)*L(i,:);
  endfor
  % GRAFICACI�N
  plot (x,y,'ok')
  hold on;
  grid on;
  y1 = polyval(P,x);
  plot (x,y1,'k','linewidth',2)
  % GR�FICA DE LOS COEF. DE LAGRANGE L0, L1, L2, L3
  x_L = linspace(3,9,50);
  y_L0 = polyval(L(1,:),x_L);
  plot (x_L,y(1)*y_L0,'*m')
  y_L1 = polyval(L(2,:),x_L);
  plot (x_L,y(2)*y_L1,'*g')
  y_L2 = polyval(L(3,:),x_L);
  plot (x_L,y(3)*y_L2,'*b')
  y_L3 = polyval(L(4,:),x_L);
  plot (x_L,y(4)*y_L3,'*y')
endfunction
