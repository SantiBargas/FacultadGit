#Ejercicio6TP05.m
clear all; clc;clf

x=linspace(-1,1,21);

# valores de datos sin perturbar
%f=sin(2*pi*x);

% Valores de datos perturbados
perturbacion = 1.e-04;
f=sin(2*pi*x)+(-1).^[1:21]*perturbacion;

# Con Octave
xx=linspace(-1,1,201); %para graficar

gr=20; #grado del polinomio de lagrange
p=polyfit(x,f,gr); %Permite encontrar el polinomio de grado n que mejor se ajusta a los datos dados.
% USAMOS EL POLINOMIO CALCULADO
z=polyval(p,xx);
% LO GRAFICAMOS
figure(1)
% GRAFICAMOS LOS PUNTOS DADOS.
plot(x,f,'bo', 'MarkerEdgeColor','k',...
'MarkerFaceColor',[0.49 1 0.63],'MarkerSize',10)
hold on % para graficar el Spline en la misma grafica.

% Graficamos el polinomio de Lagrange
plot(xx,z,'g-','linewidth',3)

