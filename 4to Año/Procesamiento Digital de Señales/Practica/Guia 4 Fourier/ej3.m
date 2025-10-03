1;

fm=100;
fs=10;
T=1/fm;
t=0:T:1-T;
sen1=sin(2*pi*fs*t); #señal x sin retardo
Sen1T=fft(sen1); #anti transformada de sin retardo

sRetardo = sin(2*pi*fs*t + T*10) %T*10 significa que nos desplazamos 10 unidades de tiempo

%dominio frecuencial: representación de una señal en términos de su contenido de frecuencia.
n=length(t);  %100
df=fm/n;    # 100/100
f=-fm/2 : df : fm/2-df; #desde -50 hasta 49

%libro pag 88

##exp2=exp(1).^(-j*2*pi*f*10/T);
exp2=e.^(((i*2*pi*10).*k)/N); #propiedad de retraso temporal, 10 cantidad de muestras que retardamos



%Transformar (sRetardo) = Sen1T*exp2
%Sen1T*exp2 multiplicacion elemento a elemento para aplicar el desplazamiento
sRetardo2=Sen1T.*exp2

%Anti transformamos para obtener la señal
sRetardoAntiTransformado = ifft(sRetardo2); % Se realiza la antitransformada de Fourier de la señal S.*exp2. Esto devuelve la señal en el dominio temporal.

subplot(2, 1, 1);
plot(t, sRetardo, 'r');
title('Señal con retardo');

subplot(2, 1, 2);
plot(t, sRetardoAntiTransformado, 'b');
title('Señal anti-transformada con retardo');
#vemos que la señal retardada es igual a la señal multiplicada por la exponencial


#generamos señal x sin retardo
#anti transformamos señal sin retardo
#multiplicamos transformada de la señal sin retardo por una exp compleja

