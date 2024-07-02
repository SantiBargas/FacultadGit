clc;
clear all;
N=40;
A=zeros(N,N);
b=zeros(N,1);

for i=1:N
  b(i) =(1.5*i) - 6;
  for j=1:N
    if(j==i)
      A(i,j)=2*i;
     elseif(j == (i-1))
          A(i,j)= -1;
      elseif((j == (i+1)) & i != 40)
            A(i,j)=-1;
          endif
    endfor
  endfor
 [x] = gauss(A,b);
 x(1)
 x0=zeros(N,1);
 maxit=2500;
 tol=1e-5;
[x,r,it1] = Jacobi(A,b,x0,maxit,tol);
it1
[x, r, it2, t] = GaussSeidel(A, b, x0, maxit, tol);
it2
[x, rh, it3, t] =sor(A, b, x0, maxit, tol, 1.1);
it3
disp('w optimo');
format long
[wmin] = w_optimo(A,b)
[w] = w_optimo(A)
