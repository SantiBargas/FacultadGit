clc; clear all;
format long;
n=40; %numero de filas
A=zeros(n,n); % Matriz de n x n de ceros
b=zeros(n,1);

for i = 1:n
  for j = 1:n
      if (j == i)
        A(i,j) = 2*i;
      elseif (j == i+1)
        A(i,j) = -1;
      elseif (j == i-1)
        A(i,j) = -1;
      else
        A(i,j) = 0;
      endif

  endfor
endfor

for i=1:n
    b(i,1)=(1.5*i)-6;
  endfor


%x0 el vector nulo
x0=zeros(40,1);
maxit=2000;
tol=1e-5;
w=1.1;

[x] = gauss(A,b);
disp("El valor x1 es :" )
x(1)

[xJac,rJac,itJac,tJac] = Jacobi(A,b,x0,maxit,tol);
disp("Las iteraciones de Jacobi son")
itJac

[xGauss, rGauss, itGauss, tGauss] = GaussSeidel(A, b, x0, maxit, tol);
disp("Las iteraciones de GaussSeidel son")
itGauss

[xSor, rhSor, itSor, tSor] =sor(A, b, x0, maxit, tol, w);
disp("Las iteraciones de GaussSeidel son")
itSor


[wmin] = w_optimo(A,b);
disp("El w optimo es:")
wmin



