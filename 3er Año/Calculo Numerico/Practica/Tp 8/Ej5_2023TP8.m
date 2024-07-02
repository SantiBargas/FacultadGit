%Ej5_2023TP8.m
%el problema de valores de contorno lineal con
% condicion mixta adapatada a Neumann
% y’’ = p(x)y’ + q(x)y + r(x) para x en [a,b]
% y(a)=alpha , Ay’(b) + By(b) = C (COND. MIXTA)
% f: funcion columnas con las funciones p,q,r
% PVC calentamiento de una barra de cobre con una fuente. Difusion-reaccion
% Ley de enfriamiento de Newton
% PVC tipo Robin -K0*u'(L) = H(u(L)-ue);
% ARMADO DE LA CONDICION
% Ej: -0.9*u'(3)-15*u(3)= -15*4 ====> [-0.9 -15  -60]

clear all;clc

Largo=3;                   % Longitud de la barra
y0=21;                      % temperatura extremo izquierdo
Hnewton=0;                % Coeficiente convectivo en la frontera
ue=0;                      % Temperatura exterior
K0 = 1;                   % Conductividad termica (depende del material)
fuente=@(x) 20*sin(5*(x-1));    % Fuente de calor "r"
%fuente=@(x) 20*x;
pR = @(x) 0.*x;      % proceso reactivo

f =@(x) [(1/K0)*0.*x  (1/K0)*pR(x)  -(1/K0)*fuente(x)];
%h=0.01;
%L = Largo/h;
L=100;
inter=[0 Largo];
rob=[-K0 0 0];
[xDFR,yDFR] = dif_fin_rob(f,inter,y0,rob,L);
%=======================================================================
figure(1)
xx=linspace(0,300,201);
plot(xx,fuente(xx),'r-')
title('Funcion Fuente de calor')
xlabel('posicion: X')
ylabel('Fuente')

figure(2)
plot(xDFR,yDFR,'b-*');
title('Temperatura a la largo de la barra calculada por DFinitas con h=0.1')
xlabel('posicion: X')
ylabel('Temperatura')
grid on;
grid minor

yDFR(end)
max(yDFR)