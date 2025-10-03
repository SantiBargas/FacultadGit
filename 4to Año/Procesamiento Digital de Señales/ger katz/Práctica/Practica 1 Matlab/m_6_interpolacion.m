%6)
ti=0;
tf=2;
fm=10;
fs=1;
fi=0;

[t,xArbitraria,tAux,xI]=interpolacion(ti,tf,fm,fs,fi);
plot(t,xArbitraria);
hold on;
stem(tAux,xI);

function xArbitraria=arbitraria(fs,t,fi)
xArbitraria=sin(2*pi*fs*t+fi);
end

function x = IEscalon(t)
    if(t>=0 && t<0.99)
        x = 1;
    else
        x = 0;
    end
end

function x=ILineal(t)
x=(1-abs(t)) * (abs(t)<1);
end

function x=ISinc(t)
if(t~=0)
   x = (sin(pi.*t)./(pi.*t));
else
    x = 1;
end
end

function [t,xArbitraria,tAux,xI]=interpolacion(ti,tf,fm,fs,fi)
Tm=1/fm;
TmAux=Tm/4;

t=ti:Tm:tf-Tm;
tAux=ti:TmAux:tf-TmAux;

xArbitraria=arbitraria(fs,t,fi);

tamN=length(t);
tamM=length(tAux);
a=input('1)Escalon, 2)Lineal, 3)Sinc: ');
i=1;
switch a
    case 1
        for m=1:tamM
            suma=0;
            for n=1:tamN
                xAux=xArbitraria(n); %=arbitraria(fs,n*Tm,fi)
                xEscalon=IEscalon((tAux(m)-t(n))/Tm); %=(m*TmAux-n*Tm)/Tm
                suma=suma+xAux*xEscalon;
            end
            xI(m)=suma;
        end
    case 2
       for m=1:tamM
            suma=0;
            for n=1:tamN
                xAux=xArbitraria(n);
                xLineal=ILineal((tAux(m)-t(n))/Tm);
                suma=suma+xAux*xLineal;
            end
            xI(m)=suma;
        end
    case 3
       for m=1:tamM
            suma=0;
            for n=1:tamN
                xAux=xArbitraria(n);
                xSinc=ISinc((tAux(m)-t(n))/Tm);
                suma=suma+xAux*xSinc;
            end
            xI(m)=suma;
        end
end
end

