%H(s) evaluada en s=jw obtenemos la respuesta en frecuencia H(jw) de este sistema
%agarramos un vector de w desde 0 hasta algun valor
pkg load signal

fm=4000; #vamos incrementando fm hasta que pueda caer 3 decibeles el valor
w=0:fm;

##Definición de la función de transferencia en el dominio de Laplace
s=1i.*w;  #forma de definir una variable compleja
H=(12500*s)./((44*(s.^2))+(60625*s)+6250000); %-> H(jw)

##Gráfica de la magnitud de la respuesta en frecuencia:
figure(1)
plot(w,(abs(H)));

##encontrar la frecuencia de corte del sistema continuo.
##Esto es la frecuencia donde la respuesta cae 3 dB respecto al valor máximo.

posHMax = find(H==max(H));
HMax = H(posHMax);
posw0=0;
decibeles = 10 * log10( (H.^2)/HMax^2);

for i = posHMax:length(decibeles)
    if(decibeles(i) < -3)
      w0=decibeles(i);
      posw0=i;
      break
    end
end

f0=posw0/(2*pi); % (video) calcula la frecuencia de corte en Hz a partir de la posición de la frecuencia de corte posw0.
f_T=4*f0; %frecuencia de muestreo 4 veces superior (inciso)
T0=1/f_T; %periodo de muestreo


w=0:2*pi/4001:2*pi; %vector de frecuencias en radianes:
r=1;
z = r*exp(1i*w); %variable z en el plano z:
sEuler=(1-z.^-1)/T0; %pag 151
HEuler=(12500*sEuler)./((44*(sEuler.^2))+(60625*sEuler)+6250000);

figure(2);
plot(w,HEuler);
title("Transformacion de Euler");


sBilineal=(2/T0).*((1-z.^-1)./(1+z.^-1)); %pag 154
HBilineal=(12500*sBilineal)./((44*(sBilineal.^2))+(60625*sBilineal)+6250000);

figure(3);
plot(w,abs(HBilineal));
title("Transformacion Bilineal");





