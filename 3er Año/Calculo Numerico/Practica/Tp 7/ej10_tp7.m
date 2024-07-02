clc;
clear;

g=9.81;
l=9.81;

h=0.05;
L=(20-0)/h;

inter=[0,20];

%f=@(t,z) [z(2);-(g/l)*sin(z(1))];
%o usamos la funcion simplificada
f=@(t,z) [z(2);sin(z(1))];

 % condicion inicial, segun los diferentes puntos del ejercicio
               % y0=[posicion; velocidad]

%a
y0=[0.1;0];
[t, y] = RungeKuttaMulti(f,0,20,y0,L);
%b
y0=[0.7;0];

%c
y0=[3.0;0];

%d
y0=[3.5;0];

%e
y0=[0;1];

%f
y0=[0;1.99];

%g
y0=[0;2];

%h
y0=[0;2.01];




