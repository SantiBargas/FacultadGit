1;

fm=50;
t0=0;
t1=1;
tm=1/fm;

t=t0:tm:t1-tm;
N=length(t);
A=2;
x=A*sin(2*pi*27*t);
S=fft(x);
plot(t,x);
figure(2);
stem(S);
stem(abs(S));

%1- Un primer vistazo de la señal nos indicaria que la señal original esta
% formada por una senoidal de frecuencia 24 Hz y amplitud de 2.
% Esta deduccion no es 100% correcta, ya que deberia pasar que la magnitud
% se espeje respecto del centro, mostrando su frecuencia negativa.
% En realidad lo que pasa es que como no se cumple el teorema de muestreo,
% la transformada no representa fielmente a la señal original.
% Si se cumpliera el teorema de muestreo, el primer valor del dominio para
% el cual hay amplitud deberia ser 27 y el siguiente 27 (para fs=54 hz).

%2-
%Si se cumple el teorema de muestreo:
   %valorPos = fs
   %valorNeg = fm-fs
   
%Si no se cumple:
   %valorNeg = fs
   %valorPos = fm-fs
   
%3- Magnitud = AFourier = A*N/2
AFourier = A*N/2;
