%f(1)=0
%f(2)=4
%f(3)=22/3
%f'(1)=f'(3)=3

clc;
clear all;
x=[1 2 3]
y=[0 4 (22/3)]
dy0=3;
dyn=3;
[a, b, c, d] = Spline_Cubico_Sujeto(x, y, dy0, dyn);
