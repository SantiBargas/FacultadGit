clc;clear all;
format long;

%P(x) =  230 * x^4 + 18*x^3+ 9*x^2 -221*x - 9

P=@(x) (230*x.^4) + (18*x.^3) + (9*x.^2) -(221*x) - (9) ;
dP=@(x) (920*x.^3) + (54*x.^2) + (18*x) - (221);


xx=linspace(-1,2,201);

figure(1)
plot(xx,P(xx),'b-')
hold on;
grid on;
grid minor;
plot(xx,dP(xx),'g-')
plot(xx,y=zeros(size(xx)),'r-')
legend("FUNCION","DERIVADA","RECTA Y=0")

maxit=2000;
tol=1e-6;

[p1, rh1, it1, t1] = biseccion(P, -0.1, 0.1, maxit, tol);
[p2, rh2, it2, t2] = biseccion(P, 0.955, 0.97, maxit, tol);

disp("La raiz negativa x1 es:")
p1
disp("La raiz positiva x2 es:")
p2


%PARA BUSCAR MAXIMOS O MINIMOS NECESITAMOS LA DERIVADA DE LA FUNCION
%Buscamos donde la derivada corta al eje x
[p3, rh3, it3, t3] = biseccion(dP, 0, 1, maxit, tol);

disp("El polinomio alcanza su valor minimo en: ")
p3
disp("Y ese valor es")
P(p3)

%Para buscar punto fijo despejamos x del polinomio
% x = ((230*x.^4)/221) + ((18*x.^3)/221) + ((9*x.^2)/221) - ((221*x)/221) -((9)/221)

g=@(x) ((230*x.^4)/221) + ((18*x.^3)/221) + ((9*x.^2)/221)  -((9)/221);

[xPuntoFijo, rh, t] = puntofijo(g, 0, maxit, tol);
disp("El polinomio posee un punto fijo con la forma de g(x) declarada en:")
xPuntoFijo

