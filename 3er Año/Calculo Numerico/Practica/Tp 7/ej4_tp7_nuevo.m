clc;
clear all;
inter=[0,1];
f=@(t,y) t*exp(3*t)-2*y;
y0=0;
yexact=@(t,y)(t.*exp(3*t))./5 - (exp(3*t))./25 + (exp(-2*t))./25;
h1=0.2;
h2=0.1;
h3=0.05;
L=[ ((1-0)/h1) ((1-0)/h2) ((1-0)/h3)]'

for i=1:3
[t,y] = euler(f,inter,y0,L(i))
%[t, w] = euler_atras_nw(f, dfy, a, b, y0, N, maxit, tol)
%[t, w]=Crank_Nicholson_Newton(f, dfy, t0, tn, alpha, N, maxit, tol)

end
