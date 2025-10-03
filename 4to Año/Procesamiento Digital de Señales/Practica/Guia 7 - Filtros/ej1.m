pkg load signal

r1=0.1;
r2=0.80;
a1=45*pi/180;
a2=30*pi/180;
a3=60*pi/180;

p=[r1*exp(1i*a1) r1*exp(-1i*a1) r1*exp(1i*a1) r1*exp(-1i*a1)]
c=[r2*exp(1i*a2) r2*exp(-1i*a2) r2*exp(1i*a3) r2*exp(-1i*a3)]

%polinomio numerador y denominador
num=poly(c);
den=poly(p);

%diagrama de polos y ceros
zplane(num,den);
title('Diagrama de Polos y Ceros');
xlabel('Parte Real');
ylabel('Parte Imaginaria');

%Respuesta en frecuencia
figure
[h,w]=freqz(num,den);
plot(w,abs(h));
xlabel('Frecuencia (rad/s)');
ylabel('Magnitud');
title('Respuesta en Frecuencia');

%inciso c
z=exp(j*a1);
mn=0;
for k=1:length(num)
  mn = mn+num(k)*z^(-(k-1));
endfor

md=0
for k=1:length(num)
  md = md+den(k)*z^(-(k-1));
endfor

mm=abs(mn/md);

%normalizacion para tener magnitud imaginaria
num=num/mm;

figure
[h,w]=freqz(num,den);
plot(w,abs(h));

%inciso d
#cambiamos r1=0.95 a r1=0.6 para ver que pasa

#cuando el polo esta mas cerca del circulo unitario, mas alta la respuesta en frecuencia
#cuando el polo esta mas cerca del origen parte de la derecha casi 0, parte de la izquierda mas alto en el circulo unitario

%e
fm=200;
T=1/fm;
t1=0:T:2-T;
x1=sin(2*pi*15*t1)+sin(2*pi*25*t1);

figure
plot(abs(fft

%d
fm=120;
T=1/fm;
t2=0:T:2-T;
x2=sin(2*pi*15*t2)+sin(2*pi*25*t2);

plot(t2,x2);
y2=filter(num,den,x2);

