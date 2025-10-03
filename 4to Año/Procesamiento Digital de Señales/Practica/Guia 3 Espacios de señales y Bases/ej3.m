function ej3
%discretizamos la señal
##fm=100;
##tm=1/fm;
##t=-1:tm:1-tm;
##y=-1*(t<0) + 1*(t>=0);

##[t,y]=ej1_a_senoidal(0,1,100,1,1,0);
##[t,y]=ej1_c_cuadrada(0  ,  1,  500,1,1,0);
[t,y]=cuadrada(100)

####    1    ####################################################
 %pag 62
  %Aproximacion : error cuadratico total usando ejemplo de legendre

  a0=0;
  a1=sqrt(3/2);
  a2=0;
  a3=-sqrt(7/32);

  b0=1/sqrt(2);
  b1=sqrt(3/2)*t
  b2=sqrt(5/2)*((3/2)*t.^2-(1/2))
  b3=sqrt(7/2)*( ((5/2)*t.^3) - ((3/2)*t));

  yAprox= (a1 * b1) + (a3*b3)

 figure
 stem(t,y)
 hold on
 stem(t,yAprox)
 legend('funcion','errorcuadratico')

 disp("El error total es")
 errorTot = sum((y-yAprox).^2)


 ####    2    ####################################################
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
figure(2);
surf (alpha1,alpha3, errorTot2);
xlabel ( 'Alpha 1' );
ylabel ( 'Alpha 3' );
zlabel ( 'Error cuadratico total' );
## disp("El error total2 es")
## errorTot2

 ####    3    ####################################################
%Mas coeficientes para comprobar como se reduce el error cuadratico

%3
%Agregamos dos terminos a la aproximacion, vemos que el error disminuye
a5 = (1/8)*sqrt(11/2);
b5 = sqrt(11/2)*((63/8)*(t.^5)-(35/4)*(t.^3)+(15/8)*t);
yaprox3 = a1 * b1 + a3 * b3 + a5 * b5;

errorTot3=sum((y-yaprox3).^2);

figure(3);
stem(t,y);
hold on;
stem(t,yAprox,'r');
stem(t,yaprox3,'g');
 legend('funcion','errorcuadratico1','errorcuadratico2')
 disp("El error total3 es")
 errorTot3











