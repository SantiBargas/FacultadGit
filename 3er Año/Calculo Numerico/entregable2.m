%limpiamos ventana
clc
clear

k=0.04; %Constante de equilibrio
p=3.5; %atm

%DEFINIMOS LA FUNCION Y SU DERIVADA
f= @(x) ((x/(1-x))*sqrt(2*p./(2+x))) - k
df=@(x) ((x^3+(3*x)-4))/((k^2)*(x^3));

%FIJAMOS LA MAXIMA ITERACION Y LA TOLERANCIA
maxit=100000;
tol=1e-8;

%GRAFICAMOS LA FUNCION
m=linspace(-10,10,250);
plot(m,f(m));

format long;

disp("BISECCION")
a=0;
b=0.5;
[pBis, rh, it, t] = biseccion(f, a, b, maxit, tol);

disp("SECANTE")
x0=0;
x1=0.5;
[xSec, rh, it, t] = secante(f, x0, x1, maxit, tol);
pBis
xSec

p= @(x) ( (k.*(1-x)./x).^2*(2+x) ) /2 ;
x=0.02; %fraccion molar

disp("La presión total de la mezcla necesaria para disociar una fracción molar x=0.02 es:")
p(0.02)



