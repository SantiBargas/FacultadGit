clc
clear

f= @(x) sin(x)+cos(1+x.^2)-1;
df = @(x) cos(x)-sin(1+(x.^2)).*(2*x);


t=linspace(0,5,200);
figure(1)
plot(t,f(t),'r')
hold on;
grid on;
plot(t,df(t),'b')

%las raices positivas menores a 5 estan entre
% x0=1.9 x1=1.95
%x2=2.5 x3=2.55


kmax=10000;
maxit=10000;
tol=1e-10;  %porque dice 10 digitos correctos


disp("NEWTON")
xn1=1.94; %numero cerca de la raiz para darnos cuenta hay q graficar la funcion
xn2=2.53
[xNew1,rh,it,t] = NewtonRaphson(f,df,xn1,kmax,tol);
[xNew2,rh,it,t] = NewtonRaphson(f,df,xn2,kmax,tol);
disp("Las raices con newton son:")
xNew1
xNew2

disp("SECANTE")
%precisa dos puntos cerca de la raiz
x0=1.9 ;
x1=1.95;
x2=2.5 ;
x3=2.55;
[xSec1, rh, it, t] = secante(f, x0, x1, kmax, tol);
[xSec2, rh, it, t] = secante(f, x2, x3, kmax, tol);
disp("Las raices con secante son:")
xSec1
xSec2

disp("BISECCION")

[pBis1, rh, it, t] = biseccion(f, x0, x1, maxit, tol);
[pBis2, rh, it, t] = biseccion(f, x2, x3, maxit, tol);
disp("Las raices con biseccion son:")
pBis1
pBis2




