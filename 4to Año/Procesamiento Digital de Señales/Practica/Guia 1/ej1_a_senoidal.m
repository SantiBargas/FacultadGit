
function[t,y]=ej1_a_senoidal(tini,tfin,fm,fs,A,fi)


%t ini tiempo inicial
%t fin tiempo final
%fm frecuencia de muestreo número de veces que se toma una muestra de una señal en un segundo
%fs frecuencia senoidal  número de oscilaciones completas que la señal completa en un segundo
%fi angulo


 T=1/fm; %T periodo de muestreo cada cuanto toma una muestra
 t=tini:T:tfin-T; %Vector de tiempos
 %10Hz -> 10 muestras por segundo

 y= A.*sin(2*pi*fs*t+fi);

## figure;
## plot(t,y);
##
## figure;
## stem(t,y);
endfunction;
 %[t,y]=ej1_a_senoidal(0,1,100,1,1,0);

