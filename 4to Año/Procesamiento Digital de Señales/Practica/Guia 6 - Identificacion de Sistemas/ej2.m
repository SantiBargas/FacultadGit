s=load('eeg.txt');
s=s/max(abs(s));

%Calculo la funcion de autocorrelacion para retardos de 0 a 8; por iniciso del ejer entre 4 y 8;
r=acorr(s,8);

%aplico el algoritmo de levinson-durbin con retardo 8
[A,E]=levin(r,8);

%Uso el criterio de akaike para estimar el orden
p=akaike(E,length(s));
disp(['Orden Optimo: ' num2str(p)]);

%Calculo la respuesta en frecuencia para el sistema estimado
[h,w]=freqz(1,[1; A(:,p)]);
fm=250;
h1=subplot(2,1,1);
plot(fm*w/(2*pi),abs(h)); %ESCALA HORIZONTAL EN HZ
title('Respuesta en Frecuencia del Sistema Estimado');
xlabel('Frecuencia (Hz)');
ylabel('Magnitud');


%Calculo la TF de la señal de entrada
S=fft(s);
N=length(s);
M=N/2+1;
f=(fm/N)*[0:M-1]; #vector de frecuencias
h2=subplot(2,1,2);
plot(f,abs(S(1:M)));
linkaxes([h1,h2]);
title('Transformada de Fourier de la Señal de Entrada');
xlabel('Frecuencia (Hz)');
ylabel('Magnitud');



