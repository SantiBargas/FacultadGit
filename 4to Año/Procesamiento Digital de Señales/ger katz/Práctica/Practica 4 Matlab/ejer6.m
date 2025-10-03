1;
clear;
% Cargo
x = load ('necg.txt');
figure(1);
plot(x);
n = length(x);
fm=360;
tm=1/fm;
tf=n*tm;
t=0:tm:tf-tm;

% dominio frecuencial
df = fm/n;
f = -fm/2:df:fm/2-df;

% transforamda
figure(2);
S=fft(x);
S=[S(n/2+1:n); S(1:n/2)];
stem(f,abs(S));

for i=1:n
   if(abs(f(i)) >= 40)
      y(i) = 0;
   else
       y(i) = S(i);
   end
end
% filtrada
figure(3);
stem(f,abs(y));

y=[y(n/2+1:n) y(1:n/2)];
xAnti=real(ifft(y));

%Filtrada y ordenada
figure(4);
plot(t,xAnti);