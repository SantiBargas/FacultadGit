clc;
clear all;

pt=3.5;
K=0.04;

%K= (x/1-x) * sqrt((2*pt)/(2+x))
%DESPEJAMOS K PARA DEFINIR LA FUNCION
f=@(x) (x./(1-x)) .* sqrt((2*pt)./(2+x)) - K;

%GRAFICAMOS LA FUNCION
m=linspace(-10,10,250);
plot(m,f(m),'b-');
hold on
plot(m,y=zeros(size(m)),'r-')

[p, rh, it, t] = biseccion(f, -0.05, 0.05, 1000,1e-6);
disp("El valor de x en donde disocia es:")
p


%------------------------------------------------------%
%b)
%Despejamos p

pt= @(x) ( (K*(1-x)/x)^2*(2+x) ) /2 ;
x=0.02; %fraccion molar

disp("La presion total necesaria para disociar una fraccion de x=0.02 es:")
pt(0.02)
