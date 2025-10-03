%para el impulso se utiliza el delta de dirac: δ[n] = (1 si n=0, 0 en otro caso)
%escrito en forma de vector: δ[n] = [1 0 0 0 ...]
% es decir x(n) = δ(n)
%
%δ[n] -> h[n]
%
%condiciones iniciales 0
%1.
%y[n] − y[n − 2] = x[n]
%
%y[n] = x[n] + y[n-2]
%
%h[0] = δ[0] + y[-2] = 1 + 0 = 1
%h[1] = δ[1] + y[-1] = 0 + 0 = 0
%h[2] = δ[2] + y[0] = 0 + 1 = 1
%h[3] = δ[3] + y[1] = 0 + 0 = 0
%h[4] = δ[4] + y[2] = 0 + 1 = 1
%
%para hacer programa:
%las y las represento con a y las x con b
%y[n] − y[n − 2] = x[n]
%
x = [1, zeros(1, 99)]; % Impulso delta[n] en n = 0

a=[1 0 -1]; %vector del retardo
b=[1];
h = filter(b,a,x);
stem(h);
%como no toma un valor fijo es IIR
%

%2.
%y[n] = x[n] + 0,5x[n − 1]
%
a=[1];
b=[1 0.5];
h = filter(b,a,x);
##stem(h);
%tiende a 0, FIR duracion finita
%

%3.
%y[n] − 0,5y[n − 1] + 0,25y[n − 2] = x[n]
%
a=[1 -0.5 0.25];
b=[1];
h = filter(b,a,x);
##stem(h);
%va a 0, FIR duracion finita
%
%Para clasificar:
%FIR (respuesta al impulso finita) si luego de un impulso la respuesta se hace 0
%IIR (respuesta al impulso infinita) si luego de un impulso la respuesta no toma un valor fijo
