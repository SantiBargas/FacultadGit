clear all; clc;clf
m1=1;
m2=3;
k1=3;
k2=4;



%f=@(t,x) [x(3); x(4); (-k1*x(1)/m1)-((k1*(x(2)-x(1)))/m1) ; (-k2*(x(2)-x(1)))/m2]

%f = @(t,x) [x(3);...
%            x(4);...
%            -((k1+k2)/m1)*x(1)+(k2/m1)*x(2); ...
%            -(k2/m2)*(x(2)-x(1)) ];

x0=[0;0;1;1]; %posx=0 posy=0 velinix=1 veliniy=1;

inter=[0 ,20];

L=1600;

[t,x] = rk4JJ(f,inter,x0,L);

posk1=(x(end,1))

posk2=x(end,2)
