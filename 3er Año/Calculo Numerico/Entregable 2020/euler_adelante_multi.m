function [t,y] = euler_adelante_multi(f,a,b,y0,N)
  h = (b-a)/N;
  t = [a:h:b];
  y = zeros(length(y0), N+1);
  y(:,1) = y0;

  for n = 1:N
    y(:,n+1) = y(:,n) + h*f(t(n),y(:,n));
  endfor
endfunction
