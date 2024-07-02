clc ;
clear all;

inter=[0,20];

%paso h=0.05;
h=0.05;
L=(20-0)/h;
x0=[-1;1];

f=@(t,x) ([-t.*x(2) ; t.*x(1)-t.*x(2) ]);

[t,x] = euler_adelante_multi(f,0,20,x0,L);

figure(1)
plot(x(1,:), x(2,:), "linewidth", 2);
title('Trayectoria de la particula')
xlabel('X1')
ylabel('X2')

figure(2)
plot(t,x(1,:), "linewidth", 2);
hold on;
plot(t, x(2,:), "linewidth", 2);

