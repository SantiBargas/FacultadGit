%Ej5_examen2021TP8_01.m
%el problema de valores de contorno lineal con
%condicion mixta
% y’’ = p(x)y’ + q(x)y + r(x) para x en [a,b]
% y(a)=alpha , Ay’(b) + By(b) = C
% f: funcion columnas con las funciones p,q,r
% PVC calentamiento de una barra de cobre con una fuente. Difusion-reaccion
% Ley de enfriamiento de Newton
% PVC tipo Robin -K0*u'(L) = H(u(L)-ue);
% Ej: -0.9*u'(3)-15*u(3)= -15*4 ====> [-0.9 -15  -60]
clear all;clc
Largo=3;                   % Longitud de la barra
y0=21;                      % temperatura extremo izquierdo
Hnewton=5;                % Coeficiente convectivo en la frontera
ue=10;                      % Temperatura exterior
K0 = 1                    % Conductividad termica (depende del material)
fuente=@(x) 20*sin(5*(x-1));    % Fuente de calor "r"
pR = @(x) 0.*x;      % proceso reactivo

f =@(x) [(1/K0)*0.*x  (1/K0)*pR(x)  -(1/K0)*fuente(x)];
%h=0.01;

L=300;

h = Largo/L;
inter=[0 Largo];
rob=[-K0 -Hnewton -5*ue];
[xDFR,yDFR] = dif_fin_rob(f,inter,y0,rob,L);

figure(1)
plot(xDFR,yDFR,'b-*');
title('Temperatura a la largo de la barra calculada por DFinitas con h=0.1')
xlabel('posicion: X')
ylabel('Temperatura')
grid on;
grid minor

Temp_ext_der=yDFR(end)

Flujo_ext_der=-((Temp_ext_der)-yDFR(end-1))/h
Flujo_ext_der_01=Hnewton.*(Temp_ext_der-ue)