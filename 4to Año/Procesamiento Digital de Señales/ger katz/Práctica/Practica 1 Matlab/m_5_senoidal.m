%5) fs=4000Hz, t0=-1, t1=1, fm=129Hz, fi=0
function [t,x]=m_5_senoidal(ti,tf,fm,fs,fi)
T=1/fm;
t=ti:T:tf-T;
x=sin(2*pi*fs*t+fi);
plot(t,x);
end

%La grafica muestra 2 ciclos en 2 segundos, por lo tanto la frecuencia es
%de 1 Hz.
%La frecuencia de la señal es muy grande comparada con la frecuencia de
%muestreo, por lo tanto se pierde informacion y no se muestran todos los
%ciclos.