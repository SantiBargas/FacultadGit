  1;
clear;
fm=4000;
w=0:fm;
s=1i.*w;
H=(12500*s)./((44*(s.^2))+(60625*s)+6250000);

figure(1)
plot(w,20*log(abs(H)));

%Posicion donde el H es maximo
poshMax=find(H==max(H));
hMax=H(poshMax);
posw0=0;
decibeles=10*log10((H.^2)/(hMax^2));
for i=poshMax:length(decibeles)
    if(decibeles(i)<-3)
        w0=decibeles(i);
        posw0=i;
        break;
    end
end

f0=posw0/(2*pi);
f_T=4*f0;
T0=1/f_T;

figure(2);
w=0:2*pi/4001:2*pi;
r=1;
z = r*exp(1i*w);
sEuler=(1-z.^-1)/T0;
HEuler=(12500*sEuler)./((44*(sEuler.^2))+(60625*sEuler)+6250000);
plot(w,20*log(abs(HEuler)));

figure(3);

sBilineal=(2/T0).*((1-z.^-1)./(1+z.^-1));
HBilineal=(12500*sBilineal)./((44*(sBilineal.^2))+(60625*sBilineal)+6250000);
plot(w,20*log(abs(HBilineal)));
    