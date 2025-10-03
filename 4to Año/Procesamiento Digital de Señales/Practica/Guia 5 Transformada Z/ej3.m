%POLOS: Valores en los que H(z) se hace infinito, es decir que el denominador sea cero
%CEROS: Valores que h(z) valga 0, numerador = 0
%ESTABLE: Una entrada acotada, la salida es acotada. En el plano s todos los polos del sistema
%estuvieran del semiplano con valores negativa (lado del semiplano izquierdo)
% y en el plano z deben estar dentro del circulo unitario

%NO ESTABLE: Una entrada acotada, y la salida se va al infinito

%RESPUESTA AL IMPULSO: A partir de H(Z)=Y(Z)/X(Z) deducimos la ecuacion principal
%luego le ponemos un impulso de entrada y calculamos la salida

pkg load signal

% Definir la función de transferencia H(z)
numerador = [1, -2, 2, -1];
denominador = [1 -1.7 0.8 -0.1];  % -> se obtiene de expandir el denominador, son las const de cada z

raices_num=roots(numerador); #sacamos donde se hace 0 el numerador #CEROS
raices_den=roots(denominador); #sacamos donde se hace 0 el denominador #POLOS

% 1. Dibujar el diagrama de polos y ceros
figure;
zplane(raices_num, raices_den);
legend(,'Circulo Unitario','Ceros', 'Polos');
title('Diagrama de polos y ceros');

%2 Respuesta al impulso
%Se obtiene de expandir H(z)=Y(z)/X(z) a y(n)=x(n)
y_const=[1 -1.7 0.8 -0.1];
x_const=[1 -2 2 -1];
y=respuestaImpulso(y_const,x_const,20);
figure;
plot(y);
title("Respuesta al impulso")
##
##Para determinar si el sistema es estable, podemos observar la ubicación de los polos en el plano 𝑧
##z. Si todos los polos están dentro del círculo unitario en el plano 𝑧
##z, entonces el sistema es estable.
