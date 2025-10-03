1;
t=0:0.01:1;
fs1=2;
fs2=2;
y1=sin(2*pi*t*fs1+pi/2);
y2=sin(2*pi*t*fs1);
y3=sin(2*pi*t*fs2);

yFinal=dot(y3,y2)

plot(t,y1);
hold on;
plot(t,y2);
plot(t,y3);

%Distinto phi hace que sean mas parecidas o no
%Para la frecuencia depende si son multiplos de acuerdo al
%periodo del seno. Por ej, sin(2pi) y sin(4pi) dan lo mismo.