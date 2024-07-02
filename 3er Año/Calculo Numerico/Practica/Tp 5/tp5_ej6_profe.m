#Ejercicio6TP05.m
clc;
clear;

x = linspace(-1,1,21);
xi = linspace(-1,1,21);

# Problema sin perturbación
y = sin(2*pi*x);
[P, L] = Lagrange(x,y);

[a, b, c, d] = Cubic_Spline_Natural(x,y);
S = PolinomioSpline(a, b, c, d, x);

% LO GRAFICAMOS
figure(1)
% GRAFICAMOS LOS PUNTOS DADOS.
plot(x,y,'bo')
hold on

% Graficamos el polinomio de Lagrange
plot(x,polyval(P,x),'m-')

% Grafica de la función Spline Cúbica Natural
plot(x,polyval(S,x),'k-')

grid on
grid minor
xlabel('Datos X')
ylabel('Funcion (f(x))')
title('Análisis de la función con datos sin perturbación')
