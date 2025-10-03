function [t,sinc] = ej1_b_sync(tini,tfin,fm,fs)

%t ini tiempo inicial
%t fin tiempo final
%fm frecuencia de muestreo número de veces que se toma una muestra de una señal analógica por unidad de tiempo
%fs frecuencia senoidal  número de oscilaciones completas que la señal completa en un segundo

 T=1/fm;

 t=tini:T:tfin-T; %Vector de tiempos
 %10Hz -> 10 muestras por segundo

x=2*pi*fs*t;

sinc=sin(x)./x;
sinc(x==0)=1;

##if(x!=0)
##  sinc=sin(x)./x;
##elseif (x==0)
##  sinc=1;
## endif
##endif

plot(t,sinc)

endfunction

%[t,sinc] = ej1_b_sync(-1,1,100,5);
