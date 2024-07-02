clc
clear all

%como pide determinar los instantes de tiempo donde la energia es
%igual a 1.5 planteamos
% e(t)=1.5 -> e(t)-1.5 = 0
f = @(t) (((t+1/3).^3) + 1/3).* (e.^-t) - (1.5); %funcion restando
f_2=@(t) (((t+1/3).^3) + 1/3).* (e.^-t); %funcion normal
df_2= @(t) (e.^-t) .* ((3*(t+1/3).^2) - (t+1/3).^3); %primer derivada
df2_2=@(t) (e.^-t) .* ((3*(t+1/3).^2) - (t+1/3).^3) - (e.^-t) .* ((6*(t+1/3)) - (3*(t+1/3).^2)); %sda derivada

tol=1e-5;
maxit=100;
x=linspace(0,10,2000);
%figure(1)
%plot(x,f(x),'r')
%hold on;

%la primer raiz esta entre 1 y 2
%la segunda raiz esta entre 3.5 y 4.5
[pBis, rhBis, itBis, tBis] = biseccion(f, 1, 2, maxit, tol);
[pBis2, rhBis2, itBis2, tBis2] = biseccion(f, 3.5, 4.5, maxit, tol);

disp("Los instantes de tiempo para el cual e(t) = 1.5 son")
pBis
pBis2

figure(2)
plot(x,f_2(x),'r')
hold on;
plot(x,df_2(x),'b')
plot(x,df2_2(x),'y')

disp("La maxima energia del sistema ocurre en")
%[xNew,rh,it,t] = NewtonRaphson(df_2,df2_2,0,maxit,tol);
%xNew
[xSec, rhSec, itSec, tSec] = secante(df_2, 2, 4, maxit, tol);
xSec
disp(" y es :")
max=f_2(xSec)

%para buscar la maxima tasa de crecimiento instantanea usamos la 2da derivada
[xSecC, rh, it, t] = secante(df2_2, 0.5, 1, maxit, tol);
disp("La maxima tasa de crecimiento es: ")
xSecC





