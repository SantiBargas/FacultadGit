clc;
clear all;
%DATOS:
x1 = [0,2,6];
y1 = [0,4,6];
t1 = [0,1,2];
x2 = [6,3,0];
y2 = [6,2,0];
t2 = [2,3,4];



[S1,dS1,a1,b1,c1,d1]=funcion_spline(t1,x1,0,0);
[S2,dS2,a2,b2,c2,d2]=funcion_spline(t2,x2,0,0);


xx=linspace(0,6,201);

figure (1)
plot(t1,x1,'bo',t2,x2,'ro');
plot(t1,S1(x1));
