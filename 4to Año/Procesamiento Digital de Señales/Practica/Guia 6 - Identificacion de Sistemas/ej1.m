x=rand(10000,1);
x=x-mean(x);

#implementamos el sistema
#b coeficientes que multiplican la entrada x[n] que es uno solo por eso b=1;
b=1;

#a coeficientes que multiplican la salida y[n]
#y[n] -> 1   y[n-1] -> 0.3  y[n-2] -> 0.4  y[n-3] -> -0.2
a=[1 -0.3 0.4 -0.2];
y=filter(b,a,x);

r=acorr(y,10);
[A,E]=levin(r,10); #devuelve la matriz de 10x10 con los errores

pl=epf(E,r,0.01); #corremos el error de prediccion final
figure;
p2=akaike(E,length(y));

#figura 1 : error de prediccion final
#figura 2 : criterio de akaike
