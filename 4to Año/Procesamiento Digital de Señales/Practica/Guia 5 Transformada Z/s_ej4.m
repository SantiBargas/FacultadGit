clc; clear all; close all;

%Euler: tengo H(S), reemplazo las s por s=(1-z^-1)/T y eso me da H(z)
%funcion de transferencia de un sistema discreto que aproxime al sistema continuo caracterizado por H(s)

%Bilineal: reemplazo las s por 2/T * ((1-z^-1)/(1+z^-1))

%para determinar Tm analizo la respuesta en frecuencia del sistema:

% H(s) evaluada en s=jw nos da H(jw) es la respuesta en frecuencia

%nos queda en eje x omega y eje y magnitud de H

w = 0:10000;
s = 1i*w;

Hjw = zeros(1,length(s));
for j=1:length(s)
  Hjw(j) = (12500*s(j))/(44*s(j)^2+60625*s(j)+625*10^4);
endfor


##plot(w,abs(Hjw));
plot(w,20*log10(abs(Hjw))); %en dB
ylabel('|H(j\omega)|');
xlabel('\omega');

%determino la frecuencia de corte del sistema:
% frecuencia donde la respuesta cae 3dB respecto al valor maximo

%para determinar dB uso 20log10(|x|)
[dBmax, indx] = max(20*log10(abs(Hjw)));

wc = NaN;
for t=indx:length(w)
  dBw = 20*log10(abs(Hjw(t)));
  if(dBmax - dBw >= 3)
    wc = w(t);
    break;
  endif
endfor

fc = wc/(2*pi); % Hz

fm = 4*fc;
Tm = 1/fm;

%Euler: tengo H(S), reemplazo las s por s=(1-z^-1)/T y eso me da H(z)
%funcion de transferencia de un sistema discreto que aproxime al sistema continuo caracterizado por H(s)

% Transformación de Euler


%Bilineal: reemplazo las s por 2/T * ((1-z^-1)/(1+z^-1))


#digital entre 0 y pi
#graficar las dos en Hz

