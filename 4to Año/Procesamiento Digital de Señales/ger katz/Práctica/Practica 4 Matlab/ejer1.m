1;
%1.1
T=0.001;
Fm=1/T;
f1=10;
f2=20;
t=0:T:1-T;
N=length(t);

s=sin(2*pi*f1*t)+4*sin(2*pi*f2*t);
S=fft(s);

% Dominio frecuencial df = 1/T0  tal que T0 es la duración total de la señal en el tiempo.
df = Fm/N;
f = -Fm/2:df:Fm/2-df;
figure
stem(f,abs(S));
##La grafica nos muestra para cada frecuencia, un valor de amplitud que esta
##dado por la relacion: AFourier = A*Fm/2.

 %1.2
 suma1=0;
 suma2=0;
 for i=1:N
     suma1=suma1+s(i)^2;
     suma2=suma2+(abs(S(i)))^2;
 end
 suma2=suma2/N;

%1.1
 s=sin(2*pi*f1*t)+4*sin(2*pi*f2*t)+4;
 S=fft(s);
 figure
 stem(f,abs(S));

%1.2
 f1=10;
 f2=11;
 s=sin(2*pi*f1*t)+4*sin(2*pi*f2*t);
 S=fft(s);
figure
 stem(abs(S));

%1.3
 f1=10;
 f2=10.5;
 s=sin(2*pi*f1*t)+4*sin(2*pi*f2*t);
 S=fft(s);
figure
 stem(f,abs(S));

##%1.4
f1=10;
f2=10.5;
t=0:T:2-T;
N=length(t);
%df = Fm/N;
%f = -Fm/2:df:Fm/2-df;
s=sin(2*pi*f1*t)+4*sin(2*pi*f2*t);
S=fft(s);
figure
stem(abs(S));
##%Como aumenta el periodo T y en consecuencia la cantidad de muestras N,
##%aumenta la resolucion frecuencial, porque lo que se logra una resolucion
##%correcta.
