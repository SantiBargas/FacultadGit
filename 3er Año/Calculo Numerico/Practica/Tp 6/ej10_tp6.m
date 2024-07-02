%DATOS Ej10TP6
clear all; clc
%f = @(x) 20*x - (x.^3)/5;
%f = @(x) 2.5 + x.*cos(2*x);
%f=@(x) 1+x+cos(x);
%df = @(x) 20 - 3*(x.^2)/5;
%df = @(x) cos(2*x) -2*x.*sin(2*x);
%df = @(x) 1- sin(x);

f = @(x) 2.5 + x.*cos(2*x)
df = @(x) cos(2*x)-2*x.*sin(2*x)

F = @(x) 2*pi*f(x).*sqrt(1+df(x).^2);
ft = @(t) t + 1;
a = 0; b = 4; M = 20;
%RESOLUCION
%simpson compuesto
sc = simp_comp(F,a,b,M)
%trapecio compuesto
tc = trapcomp(F,a,b,M)
%regla de simpson
%s = simpson(F,a,b)
%cuadratura de gauss con n = 3
g = gauss(F,ft,a,b)
%funcion quad de octave
q = quad(F,a,b)
