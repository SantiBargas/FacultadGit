function [x]=rcubica(a)

  tol=10^-12;
  maxit=1000000000;
  %x = a^1/3
  %x^3=a;
  %f(x)=x^3-a
  f=@(x) (x^3)-a;
  [x,h]=biseccion(f, 0, a, maxit, tol);
