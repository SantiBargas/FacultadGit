% OSCILADOR ACOPLADO
% Oscilador.m
%Ejercicio proyectil
clear all; clc;clf
m1=1;
m2=3;
k1=3;
k2=4;


f = @(t,x) [x(3);...
            x(4);...
            -((k1+k2)/m1)*x(1)+(k2/m1)*x(2); ...
            -(k2/m2)*(x(2)-x(1)) ];
%x0=[0,0,1,1]; % parten del equilibrio cada masa y con velocidad 1m/s cada una.
%x0=[0,1,0,1]; % parten del equilibrio la primera masa y la segunda desfasada 1 m,
               % con velocidad NULA la primera y 1m/s la segunda masa.
x0=[0,0,1,1];
inter=[0 20];

L=1600;

[t,x] = rk4JJ(f,inter,x0,L);

%[t,y] = euler(f,inter,y0,L);

figure(1)
plot(t,x(:,1),'b-*')
hold on
grid on
grid minor
plot(t,x(:,2),'r-o')
plot([0 20],[0 0],'k-','linewidth',3)
legend('Posicion: oscilador 1','Posicion: oscilador 2')
title('Posicion de los osciladores en funcion del tiempo')
xlabel('Tiempo')
ylabel('Posicion')

size(x)

posk1=x(end,1)
posk2=x(end,2)


