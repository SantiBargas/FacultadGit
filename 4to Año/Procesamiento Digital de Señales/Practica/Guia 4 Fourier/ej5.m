clc; clear all;

%============================== 1 ======================================

fs = 27;
fm = 50;
Tm = 1/fm;

t = 0:Tm:1-Tm;
N = length(t);

deltaf = fm/N;
freq = [-fm/2 : deltaf : fm/2-deltaf];

x = 2 * sin(2*pi*fs*t);

X = fft(x);
X_acomodada = [X(N/2+1:end) X(1:N/2)];

figure();
stem(freq,abs(X_acomodada));
xlabel('Frecuencia (Hz)');

## La frecuencia observada es de 23Hz y de amplitud 2 ya que alli es donde se observan los picos en el grafico del espectro frecuencial
## La discrepancia con los 27Hz se debe al aliasing, que se produce porque
## la frecuencia de muestreo no es al menos el doble de
## la frecuencia de la senoidal, entonces habra un solapamiento entre
## las versiones desplazadas de x(f). En estas zonas se suman los aportes de
## ambas imagenes de x(f).
##
## La frecuencia de muestreo debe ser al menos 2 veces la frecuencia de la senoidal


%TEOREMA DEL MUESTREO 2*fs < fm
%                     2*27 < 50 ?
%                     54   < 50 ? NO CUMPLE

%1- Un primer vistazo de la señal nos indicaria que la señal original esta
% formada por una senoidal de frecuencia 24 Hz y amplitud de 2.
% Esta deduccion no es 100% correcta, ya que deberia pasar que la magnitud
% se espeje respecto del centro, mostrando su frecuencia negativa.
% En realidad lo que pasa es que como no se cumple el teorema de muestreo,
% la transformada no representa fielmente a la señal original.
% Si se cumpliera el teorema de muestreo, el primer valor del dominio para
% el cual hay amplitud deberia ser 27 y el siguiente 27 (para fs=54 hz).






#=================================== 2 ========================================

f_s=105;
f_m=50;

f_obs = f_m - f_s
#=================================== 3 ========================================

