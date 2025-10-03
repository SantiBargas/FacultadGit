1;

t0=0;
t1=1;
dt=1/10;
t=t0:dt:t1-dt;

[y1,y2,y3,y4]=signal(t);
vMed=valorMedio(t, y1)
vMax=maximo(t, y1)
vMin=minimo(t, y1)
vAmp=amplitud(t, y1)
vEnerg=energia(t, y1)
vAcc=accion(t, y1)
vPotMed=potenciaMedia(t, y1)
vRms=rms(t, y1)


function [y1,y2,y3,y4]=signal(t)
dt=1/length(t);
%Senoidal
fs=2;
y1=sin(2*pi*t*fs);
stem(t,y1);

%Onda cuadrada
x=mod(2*pi*fs*t,2*pi);
y3 = -1 .* (x>=pi) + 1 .* (x<pi);

%Señal aleatoria
y4=randn(length(t));

%Rampa
dt=length(t);
rampa = 0:dt:1-dt;
y2 = rampa;
end

function m = valorMedio(x, y)
    m = sum(y)/length(y);
end

function m = maximo(x, y)
    m = max(y);
end

function m = minimo(x, y)
    m = min(y);
end

function m = amplitud(x, y)
    m = max(abs(y));
end

function m = energia(x, y)
    %m = norm(y,2)^2;
    m=sum(y.^2);
end

function m = accion(x, y)
    %m = norm(y,1);
    m=sum(abs(y));
end

function m = potenciaMedia(x, y)
%m = norm(y,2)/length(x);
    m = sqrt(sum(y.^2))/length(x);
end

function m = rms(x, y)
%m= sqrt(norm(y,2)/length(x));
    m = sqrt(sqrt(sum(y.^2))/length(x));
end

