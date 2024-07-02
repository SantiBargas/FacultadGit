clc
clear all

%punto 1 x1=1 y1=0
%punto 2 x2=x y2=x^2 por la funcion
%usamos la funcion distancia=sqrt(x2-x1)^2+(y2-y1)^2
%buscamos la derivada de la funcion distancia

distancia=@(x) sqrt( (x-1).^2 + (x.^2).^2 )
%La derivada de la distancia tiene dos terminos, uno que NUNCA se
%va a hacer cero y el otro que si, entonces trabajamos con el termino que si


f = @(x) 4*(x.^3)+(2.*x)-2
df = @(x) 12*(x.^2) + (2.*x)
x0=0
kmax=10000
tol=10^-4
t=linspace(0,5,200)
plot(t,f(t))


[x,rh,it,t] = NewtonRaphson(f,df,x0,kmax,tol)
