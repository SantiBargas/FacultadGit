# Ej5TP06
clear all;
clc; clf
format long
%========================funcion 1
% f = @(x) (sin(pi*x));
% Iex = 2/pi %valor exacto de la integral
%========================

%======================== funcion 2
% f = @(x) (1./(1+x.^2));
% Iex = atan(5) - atan(-5) %valor exacto de la integral
%========================

%======================== funcion 3
 f = @(x) (abs(x)).^(3/2)
 Iex = 10*sqrt(5) %valor exacto de la integral
%========================

 % Intervalo
 a = 0; b=5; %funcion 1 y 3
 %a=-5 ; b=-5 %funcion 2


 n = 3; # nro de puntos. % Trapecio n=2 || Simpson n=3

 r=2; % Se duplican los intervalos
 j=[1:12]; % j: la cantidad de veces a dividir
 c=10; % Cantidad inicial
 L=c.*r.^(j-1)' % secuencia de subintervalos, nos da la cantidad de subintervalos
 h=1/L; % dimension de cada uno
 N=length(L); % Total general de subintervalos

 for i= 1:N
 [Q] = intNCCompuesta(f,a,b,L(i),n);
 S(i) = Q;
 E(i) = abs(Iex - S(i));
endfor

 Q=S'
 E_L = E'
% Calculamos la relacion entre Errores: R=E_(L/2)/E_L;
for i=1:11
 r(i)= E_L(i+1)./E_L(i);
endfor

% Vector Relacion
R=r';
R=[0;R]

% graficamos:
figure(1)
plot(j,E_L,'r-o','linewidth',3)
grid on; grid minor;
xlabel('Calculos realizados -Nro. Puntos')
ylabel('Error absoluto')
