clc;
clear all;
f=@(t,y) -y+sin(t)+cos(t);
y0=0;

%Para calcular L usamos la formula L=(tf-ti)/h
%L=20,40,80,160,320,640
L=[20 40 80 160 320 640]';
inter=[0,2];
N=6;
weuler=zeros(size(N));
wRK2=zeros(size(N));
wRK4=zeros(size(N));

for i=1:6
[t,yeuler] = euler(f,inter,y0,L(i));
weuler(i)=yeuler(L(i)+1);

[t,yrk2]=rk2(f,inter,y0,L(i));
wRK2(i)=yrk2(L(i)+1);

[t,yrk4]=rk4(f,inter,y0,L(i));
wRK4(i)=yrk4(L(i)+1);


end
disp("Las soluciones son:")
SOL=[L weuler' wRK2' wRK4']
