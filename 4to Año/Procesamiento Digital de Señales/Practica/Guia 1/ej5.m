function [t, y] = ej5(tini,tfin,fm,fs,A,fi)

 T=1/fm;
 t=tini:T:tfin-T; %Vector de tiempos
 %10Hz -> 10 muestras por segundo

 y= A.*sin(2*pi*fs*t+fi);
 stem(t,y)
 xlabel('Tiempo (s)');
ylabel('Amplitud');
title('Señal Senoidal de 4000 Hz muestreada a 129 Hz');


##[t, y] = ej5(0,2,129,3000,1,0)

#fs = 4000 fm = 129    2fs <= fm ? NO CUMPLE LA RELACION
#SE REALIZA EL EFECTO QUE VA MAS LENTO O HACIA ATRAS
#Y SI VEMOS EL GRAFICO SE VE QUE NO TIENE 129
#SE experimenta efectos no deseados como el alias


#Deberia graficar 8mil periodos de la onda
