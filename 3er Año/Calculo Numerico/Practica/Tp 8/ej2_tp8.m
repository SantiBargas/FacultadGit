clc; clear all;
%-----------enunciado----------------
%y'' = -(2/x)*y' + (2/x^2)*y + (sin(log(x))/x^2
%y(1)=1
%y(2)=2

%1 <= x <= 2

%y= (c1*x) + (c2/x^2) - ( (3/10)*sin(ln(x)) ) - ( (1/10)*cos(ln(x)) )

%c2 = (1/70) * (8 - 12*sin(ln(2)) - 4*cos(ln(2)))
%c1= (11/10) - c2
%-----------------------------


%intervalo
a=1;
b=2;
inter=[1,2];

%----------------------------------
h1=0.1;
h2=0.01;
L1=(b-a)/h1;
L2=(b-a)/h2;
yc = [1 2]; %puntos iniciales y(1)=1 y(2)= 2
%-------------------------------------------------------

f=@(x) [ -(2./x) (2./x.^2) (sin(log(x)))/x.^2 ];

[x1,y1]=disparo_lineal(f,inter,yc,L1)
[x2,y2]=disparo_lineal(f,inter,yc,L2)

%calculamos la exacta

c2=(1/70) * (8 - 12*sin(log(2)) - 4*cos(log(2)));
c1= (11/10)-c2;

xx1=linspace(1,2,L1+1);
xx2=linspace(1,2,L2+1);
%buscamos la exacta reemplazando en la y original
fexacta = @(x) c1.*x + (c2./x.^2)-(3/10)*sin(log(x))-(1/10)*cos(log(x));
fex1=fexacta(xx1);
fex2=fexacta(xx2);

%============================================================
% Incorporamos el problema 3
% calculo por diferencias finitas con condiciones Dirichlet
[xdif,ydif]=dif_fin_dir(f,inter,yc,L1);

fexDF=fexacta(xdif)';
%============================================================


% Graficamos todos los calculos y comparamos con la exacta.
figure(1)
plot(x1,y1,'b-*') % Solucion del metodo del disparo
hold on
plot(xx1,fex1,'r-d') % Solucion de la exacta
plot(xdif,ydif,'k-o') %solucion de diferencias finitas
xlabel('valores de x')
ylabel('Solucion de la ecuacion diferencial')
title('Metodo del disparo y Método de Diferencias Finitas')
legend("metodo disparo","exacta","dif finitas")
grid on
grid minor
hold off

% Graficamos todos los calculos y comparamos con la exacta.
figure(2)
plot(x2,y2,'b-*') % Solucion del metodo del disparo
hold on
plot(xx2,fex2,'r-d') % Solucion de la exacta
plot(xdif,ydif,'k-o') %solucion de diferencias finitas
xlabel('valores de x')
ylabel('Solucion de la ecuacion diferencial')
title('Metodo del disparo y Método de Diferencias Finitas')
legend("metodo disparo","exacta", "dif finitas")
grid on
grid minor
hold off

% Calculo del error
ErrorDisparo1=abs((fex1' - y1));
ErrorDF = abs((fexDF' - ydif));
figure(3)
semilogy(xx1,ErrorDisparo1,'b-*')
hold on
semilogy(xdif,ErrorDF,'k-d')
%loglog(xx,ErrorDisparo,'b-*')
grid on
grid minor
hold off

figure(4)
semilogy(xdif,ErrorDF,'k-d')
grid on
grid minor



