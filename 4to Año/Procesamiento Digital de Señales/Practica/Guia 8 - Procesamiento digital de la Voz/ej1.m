pkg load signal

s=load('aeiou_mas.txt');
N=1024;
a=s(3000:3000+N-1);
plot(a)
fa=a;
cr=real(ifft(log(abs(fft(a))))); %cepstrum
figure
plot(cr) %es periodico (arranca de nuevo) vemos los tiempos negativos

k=20;
fm=8000;

%liftro para la respuesta del tracto
crl=zeros(size(cr));
crl(1:k+1)=cr(1:k+1);
crl(end-k+1:end)=cr(end-k+1:end); %creamos una señal con todos 0 y copiamos el pedazo que no queremos que sea cero

%liftro para excitacion
crl=cr-crl; %eliminamos primeros y ultimos coef y nos quedamos con la parte central

figure
plot(crl);

H=real(exp(fft(crl)));
figure;
df=fm/N;
f=0:df:fm/2;
plot(f,H(1:N/2+1));

[coef,e]=lpc(a,12);
[h,w]=freqz(1,coef);
hold on
plot(w*fm/(2*pi),abs(h),'r');
