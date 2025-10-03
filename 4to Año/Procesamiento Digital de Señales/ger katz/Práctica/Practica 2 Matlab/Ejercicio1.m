1;

fs=3;
Tm=1/20;
A=5;
ti=0;
tf=1;
fi=0;
n=0:Tm:1-Tm;

%La entrada x[n] va a ser una señal cuadrada.
x=ondaCuad(n,fs,fi);

%1.1
g=funciong(n,fs,Tm,A);
y1=g.*x;
 plot(n,y1);

%1.2
n0=3;

%1.3
y3=x+2;
%plot(n,y3);

%1.4
y4=n.*x;
%plot(n,y4);

%La entrada x[n] va a ser una señal cuadrada.
function x=ondaCuad(n,fs,fi)
xAux=mod(2*pi*fs*n+fi,2*pi);
x = -1 .* (xAux>=pi) + 1 .* (xAux<pi);
end

%Para el 1.1)
function g=funciong(n,fs,Tm,A)
g=A*sin(2*pi*fs*n*Tm);
end