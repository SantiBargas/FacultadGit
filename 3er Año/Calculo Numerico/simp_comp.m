function [XI] = simp_comp(f,a,b,n)
  %n tiene q ser par entero y positivo
  # n es el numero de subintervalos en un sistema compuesto
  h=(b-a)/n;
  XI0=f(a)+f(b);
  XI1=0;
  XI2=0;
  aux=0;
  for i=1:(n-1)
    X=a+(i*h);
    if (rem(i,2)==0)
      XI2=XI2+f(X);
      else 
      XI1=XI1+f(X);
     endif 
    endfor
 XI=((h*(XI0+(2*XI2)+(4*XI1)))/3);
endfunction