1;
fm = 100;
fs = 10;
T = 1/fm;
t = 0: T: 1 - T;
s = sin(2*pi*fs*t);
S = fft(s);
sRetardado = sin(2*pi*fs*t + T*10 ); 
%T*10 significa que nos desplazamos 10 unidades de tiempo

% dominio frecuencial
n = length(t);
df = fm/n;
f = -fm/2:df:fm/2-df;

% Alternativa que dijo el profe
exp = cos(2*pi*f*10/T) - j*sin(2*pi*f*10/T); 
% Libro pag 88
exp2= exp(1).^(-j*2*pi*f*10/T);

% transformar (sretado) = S*exp2
sRetardadoAntitransformado = ifft(S .* exp2);
serasero = sRetardadoAntitransformado - sRetardado;

plot(t, sRetardado);
hold on;
plot(t, sRetardadoAntitransformado);
% Se puede ver que son re parecidas