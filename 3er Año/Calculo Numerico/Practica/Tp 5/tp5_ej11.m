clc;
clear;
clear all;
t=[4 8 12 16 20 24]'
c=[1590 1320 1000 900 650 560]'

%c(t) = be^-kt            b y k constantes > 0

%a)Determine los valores de b y de k, utilizando el m´etodo de m´ınimos cuadrado

% modelo de concentración es del tipo c(t) =b*exp(-kt)
% es decir, sigue una ley exponencial.

% Incógnitas b y k
% llamaremos h la funcion que aproxima los datos según el modelo

% vamos a usar el metodo de linealizacion de los datos.
% para ello necesitamos calcular el log(y)

lc = log(c);
N=length(t);

[coef,A,b] = minimoscuadrados(t,lc,1) %uno pq es linealizacion

b=exp(coef(2));
k=-coef(1);

h = @(t) b.*exp(coef(1).*t);

tt = linspace(4,25,201);

plot(t,c,'ok',tt,h(tt),'-b')
grid on; grid minor;
