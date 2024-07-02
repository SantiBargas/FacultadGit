clc;
clear all;
% E(t) = (((t+(1/3)))^3 + (1/3) ) * exp(-t)
% 1.5 = (((t+(1/3)))^3 + (1/3) ) * exp(-t)

e=@(t) (((t+1/3).^3) + 1/3).* (e.^-t); %funcion normal
f = @(t) (((t+1/3).^3) + 1/3).* (exp(-t)) - (1.5); %funcion restando
df= @(t) (exp(-t)) .* ((3*(t+1/3).^2) - (t+1/3).^3); %primer derivada
df2=@(t) (exp(-t)) .* ((3*(t+1/3).^2) - (t+1/3).^3) - (exp(-t)) .* ((6*(t+1/3)) - (3*(t+1/3).^2)); %sda derivada

x=linspace(0,10,2000);
figure(1)
grid on;
grid minor;
plot(x,e(x),'g')
hold on;
plot(x,f(x),'r')
plot(x,df(x),'b')
plot(x,df2(x),'y')
plot(x,y=zeros(size(x)),'black')
legend("FUNCION ORIGINAL","FUNCION RESTANDO","PRIMER DERIVADA","SEGUNDA DERIVADA");

%buscamos donde la funcion desplazada vale 0 con biseccion
maxit=1000;
tol=1e-5;

[p1, rh1, it1, t1] = biseccion(f, 0, 2, maxit, tol);
[p2, rh2, it2, t2] = biseccion(f, 3, 5, maxit, tol);
disp("Los valores para el cual e(t)=1.5 son ")
p1
p2

%Para buscar la maxima energia de la funcion buscamos donde la derivada toca el eje 0
[p3, rh3, it3, t3] = biseccion(df, 2, 4, maxit, tol);

disp("La maxima energia es:")
e(p3)
disp("En el instante de tiempo:")
p3

%Para buscar la maxima tasa de creciemiento buscamos donde se hace 0 la sda derivada
[p4, rh4, it4, t4] = biseccion(df2, 0, 2, maxit, tol);

disp("La maxima tasa de creciemiento es:")
e(p4)
disp("En el instante de tiempo:")
p4


