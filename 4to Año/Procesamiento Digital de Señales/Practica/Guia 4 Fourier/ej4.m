##Ventana de Hamming
N = 100;
n = 0:N-1;

wH = 25/50 - 25/50 * cos(2*pi*n/N);

subplot (231);
stem(n,wH);

subplot (234);
stem(n,abs(fft(wH)));

wH2 = [zeros(1,25) wH(1:2:100) zeros(1,25)]

subplot (232);
stem(n,wH2);

subplot (235);
stem(n,abs(fft(wH2)));

wH3 = [zeros(1,40) wH(1:5:100) zeros(1,40)];

subplot (233);
stem(n,wH3);

subplot (236);
stem(n,abs(fft(wH3)));
