%4) 
%ti=0, tf=0, fm=100,25,...,0.5 Hz, fs=5 Hz, fi=0
function [t,x]=m_4_senoidal(ti,tf,fm,fs,fi)
T=1/fm;
t=ti:T:tf-T;
x=sin(2*pi*fs*t+fi);
plot(t,x);
end

%Cuanto mas chica es fm, mas grande es Tm, es decir que estamos tomando
%menos muestras por ciclo. Por lo tanto cuando hace la grafica interpola
%entre menos valores y oscila menos.
% - Con 5 ciclos/s y 100 muestras/s, tengo 20 muestras por ciclo ->
% interpola entre muchos valores.
% - Con 5 ciclos/s y 1 muestra/s, tengo 1 sola muestra en total
% - Con 5 ciclos/s y 0.5 muestras/s, necesitaria 2 segundos para obtener
% una muestra (un punto en el grafica), por lo tanto no muestra nada.