##Ventana de Hamming
N = 100;
n = 0:N-1;

wH = 25/50 - 25/50 * cos(2*pi*n/N);
wHfft = abs(fft(wH));

subplot (231);
stem(n,wH);
subplot (234);
stem(n,[wHfft(1+N/2:100) wHfft(1:N/2)]);

wH2 = [zeros(1,25) wH(1:2:N) zeros(1,25)]
wH2fft = abs(fft(wH2));

subplot (232);
stem(n,wH2);
subplot (235);
stem(n,[wH2fft((1+N/2):100) wH2fft(1:(N/2))]);

wH3fft = abs(fft(wH3));
wH3 = [zeros(1,40) wH(1:5:N) zeros(1,40)];

subplot (233);
stem(n,wH3);
subplot (236);
stem(n,[wH3fft(1+N/2:100) wH3fft(1:N/2)]);
