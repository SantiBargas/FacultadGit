clc;
clear;

#datos
x=[0 1 2 3 4 5 6]';
y=[432 599 1012 1909 2977 4190 5961]';

%a)Determinar el polinomio p6 de grado menor o igual que 6 que interpola los datos de la tabla
n = length(x)-1;
cp = polyfit(x,y,n);
f = @(x) polyval(cp,x);

% o asi:
# interpolamos con lagrange
[PL, L] = Lagrange(x,y);
plag = @(x) polyval(PL,x);

%b)  Determinar la funcion lineal p1 que mejor aproxima en el sentido
%de cuadrados mınimos los datos dados (modelo lineal).
[coef1,A,b] = minimoscuadrados(x,y,1)
r1 = @(x) coef1(1).*x + coef1(2);

%c) Determinar el polinomio p2 de grado ≤ 2 que mejor aproxima
%en el sentido de cuadrados minimos los datos dados (modelo cuadratico).
[coef2,A,b] = minimoscuadrados(x,y,2)
r2 = @(x) coef2(1).*x.^2 + coef2(2).*x + coef2(3);

%d)Graficar los datos y la evoluci´on de los tres modelos calculados durante
%las seis semanas. Determinar el error cuadr´atico en cada caso. ¿cual de los
%modelos le parece que es m´as apropiado y por qu´e?

figure(1)
plot(x,y,'r*') %puntos x e y
grid on
figure(2)
plot(f(x),'m') %funcion p6
figure(3)
plot(r1(x),'b') %funcion lineal r1
figure(4)
plot(r2(x),'g') %funcion grado2 r2
figure(5)
plot(x,y,'r*', x, f(x),'m', x, r1(x), 'b', x, r2(x), 'g') %unimos todo
grid on

f10 = f(10)
r110 = r1(10)
r210 = r2(10)
%e) Predecir cual sera la cantidad de mosquitos al cabo de 10 semanas segun los
%diferentes modelos propuestos.
%¿Sigue pensando que el modelo mas apropiado es el que eligio en el item anterior?
xx=linspace(-1,10.5,201);
x10 = 10;
y10 = 14900;

figure(6)
hold on
plot(x,y,'r*', xx, f(xx),'m', xx, r1(xx), 'b', xx, r2(xx), 'g')
plot(x10,y10,'*k');
grid on;
xlabel ('Mediciones')
ylabel('Cantidad')
%legend('datos', 'p6-Grado6', 'p1-Lineal', 'p2-Cuadratico')
%el mejor es el cuadratico
