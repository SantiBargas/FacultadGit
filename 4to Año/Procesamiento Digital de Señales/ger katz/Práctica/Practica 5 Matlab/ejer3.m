% caracteriza completamente al sistema
% dado la respuesta al impulso se puede caclular la salida del sistema

% polos valores de z que hacen que h(z) valga infinito (denominador 0)
% polinomio del denominador encontrar raices
% los ceros valores que h(z) valga 0, numerador = 0

% estable cuando una entrada es acotada la salida es acotada
% estable es que las s esten en el semiplano izquierdo del plano s
% en el plano z = valores que estan dentro del circulo unitario

y_const=[1 -2 2 -1];
x_const=[1 -1.7 0.8 -0.1];

% Raices
raices_num=roots(y_const);
raices_den=roots(x_const);

%1
zplane(raices_num,raices_den)
title('Polos y ceros')

%2
a=[1 -1.7 0.8 -0.1];
b=[1 -2 2 -1];
y=respuestaImpulso(a,b,50);
plot(y);

##function x = deltaDirac(t)
##    if(t==0)
##        x = 1;
##    else
##        x = 0;
##    end
##end

##function y = respuestaImpulso(a,b,N)
##% a terminos de y
##% b terminos de x
##% N número de respuestas
##
##%Valores iniciales
##nb = length(b);
##na = length(a);
##
##for n = 1:N
##    sum = 0;
##    sumb = 0;
##    for k = 1:nb
##        sumb = sumb + b(k)*deltaDirac(n-k);
##    end
##    suma = 0;
##    for k = 2:na
##        if(n-k+1>0)
##            suma = suma + a(k)*y(n-k+1);
##        end
##    end
##    sum = sumb - suma;
##    y(n)= sum/a(1);
##end
##end

