x=csvread('necg.txt');
f_m=360; #frecuencia de muestreo
T_m=1/f_m; #Periodo
t_fin = length(x)/f_m;
delta_f = f_m/length(x); %Dominio frecuencial df=fm/N

t=0:T_m:t_fin-T_m; #Tiempo
f=0:delta_f:360-delta_f;

figure(1);
plot(t,x);
title("señal del archivo")

x_fft=fft(x);
figure(2);
##ti
stem(f,abs(x_fft));
title("Transformada de Fourier de la señal");
hold on;

%la frecuencia va de 0 a 180, pero nos pone todo en el dominio positivo
%despues de 180 es frecuencia negativa
%cortamos de 40 a 180 positivo y de 40 a 180 negativo
%una vez que pasamos de 180 arranca 180 negativo
%de 40 hz a 180 hz hubo ruido
x_fft(f>=40 & f <=180+(180-40))=0;
stem(f,abs(x_fft),"g");
legend("FFT original", "FFT filtrada");

x_filtered = ifft(x_fft);
figure(3);
hold on;
plot(t,x_filtered);
title("Señal filtrada en el dominio temporal");


