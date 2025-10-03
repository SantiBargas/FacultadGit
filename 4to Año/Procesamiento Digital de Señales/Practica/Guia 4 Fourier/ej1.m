function ej1
f1=10;
f2=20;
T=0.001; %Periodo de muestreo
Fm=1/T;
t=0:T:1-T; %Tiempo
N=length(t);


s_cont=sin(2*pi*f1*t) + 4*sin(2*pi*f2*t); %S continua
S=fft(s_cont); %Transformada Discreta de Fourier (DFT)

% Dominio frecuencial df = 1/T0  tal que T0 es la duración total de la señal en el tiempo.
df = Fm/N;
f = -Fm/2:df:Fm/2-df;
espectro=abs(S);


% Señal continua
figure
subplot(3, 1, 1);
plot(t, s_cont);
title('Señal Continua');
xlabel('Tiempo (s)');
ylabel('Amplitud');
grid on;
%Transformada discreta
subplot(3, 1, 2);
#figure
plot(t, S);
title('Trnasformada');
xlabel('Frecuencia (Hz)');
ylabel('Magnitud');
grid on;
%Espectro
#figure
subplot(3, 1, 3);
stem(f,espectro);
title('Espectro de Magnitud');
xlabel('Frecuencia (Hz)');
ylabel('Magnitud');
grid on;

#Si la señal tiene N muestras, la transformada tiene N muestras
#El espectro va desde -Fm/2 hasta Fm/2
#A cada valor del espectro le corresponde

 % RELACION DE PARSEVAL
 suma1=0;
 suma2=0;
 for i=1:N
     suma1=suma1+s_cont(i)^2;
     suma2=suma2+(abs(S(i)))^2;
 end
 suma2=suma2/N;

 disp("Relacion de Parseval");
 suma1,suma2

 %1.2
 s=sin(2*pi*f1*t)+4*sin(2*pi*f2*t)+4;
S=fft(s);
 %PARA COMPARAR CON EL ULTIMO INCISO
##figure
##plot(t,S);



 figure
subplot(3, 1, 1);
stem(f,abs(S));
title('Espectro f1=10 f2=20');
 f1=10;
 f2=11;
 S=fft(s);
subplot(3, 1, 2);
stem(f,abs(S));
title('Espectro f1=10 f2=11');

#1.3
f1=10;
f2=10.5;
s=sin(2*pi*f1*t)+4*sin(2*pi*f2*t);
S=fft(s);

subplot(3, 1, 3);
stem(f,abs(S));
title('Espectro f1=10 f2=10.5');


%1.4
f1=10;
f2=10.5;
t=0:T:2-T;
N=length(t);
%df = Fm/N;
%f = -Fm/2:df:Fm/2-df;
s=sin(2*pi*f1*t)+4*sin(2*pi*f2*t);
S=fft(s);
figure
plot(t, S);
title('Trnasformada');
xlabel('Frecuencia (Hz)');
ylabel('Magnitud');
grid on;

%Como aumenta el periodo T y en consecuencia la cantidad de muestras N,
%aumenta la resolucion frecuencial, porque lo que se logra una resolucion
%correcta.
