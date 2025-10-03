1;
clear;
%discretizamos la señal
fm=100;
tm=1/fm;
t=-1:tm:1-tm;
y=-1*(t<0) + 1*(t>=0);

%1
%calculo la aproximacion: norma 2 al cuadrado de y-yAproximado
a1 = sqrt(3/2);
a3 = -1*sqrt(7/32);
b1 = sqrt(3/2)*t;
b3 = sqrt(7/2)*((5/2)*(t.^3)-(3/2)*t);
yaprox = a1 * b1 + a3 * b3;
% Pag 62

stem(t,y);
hold on;
stem(t,yaprox,'r');

%Calculo del error cuadratico total
errorTot = sum((y-yaprox).^2);

%2
%los coeficientes dan la mejor aproximacion
%a cada alfa le sumo y resto 0.1, 0.2 y 0.3
% Genero Alpha1 y Alpha3 aleatorios
alpha1 = [-3 : 3 ] * 0.1 + a1; 
alpha3 = [-3 : 3 ] * 0.1 + a3;

% armo una matriz para ECT asi puedo graficar
n= length (alpha1);
errorTot2 = zeros (n,n);
for i= 1 : n
    for j= 1 : n
        yaprox2 = alpha1(i) * b1 + alpha3(j) * b3;
        errorTot2(i,j) = sum ((y-yaprox2).^ 2 );
    end
end
figure (2);
surf (alpha1,alpha3, errorTot2);
xlabel ( 'Alpha 1' );
ylabel ( 'Alpha 3' );
zlabel ( 'Error cuadratico total' );

%3
%Agregamos dos terminos a la aproximacion, vemos que el error disminuye
a5 = (1/8)*sqrt(11/2);
b5 = sqrt(11/2)*((63/8)*(t.^5)-(35/4)*(t.^3)+(15/8)*t);
yaprox3 = a1 * b1 + a3 * b3 + a5 * b5;

errotTot3=sum((y-yaprox3).^2);

figure(3);
stem(t,y);
hold on;
stem(t,yaprox,'r');
stem(t,yaprox3,'g');
