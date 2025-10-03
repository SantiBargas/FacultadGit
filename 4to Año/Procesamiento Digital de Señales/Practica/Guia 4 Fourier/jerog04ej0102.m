## 1.
t = 0:0.001:1-0.001;
N = length(t);

f_1 = 10;
f_2 = 20;
s = sin(2*pi*f_1*t) + 4*sin(2*pi*f_2*t) + 4;
figure(1);
stem(t,s);

S = fft(s);
figure(2)
stem(0:length(S)-1,abs(S),"r");
grid on;

## 2.
f_1 = 10;
f_2 = 11;
s = sin(2*pi*f_1*t) + 4*sin(2*pi*f_2*t);
figure(1);
stem(t,s);

S = fft(s);
figure(2)
stem(0:length(S)-1,abs(S),"r");
grid on;

## 3.
f_1 = 10;
f_2 = 10.5;
s = sin(2*pi*f_1*t) + 4*sin(2*pi*f_2*t);
figure(1);
stem(t,s);

S = fft(s);
figure(2)
stem(0:length(S)-1,abs(S),"r");
grid on;

## 4.
t = 0:0.001:2-0.001;
N = length(t);

f_1 = 10;
f_2 = 20;
s = sin(2*pi*f_1*t) + 4*sin(2*pi*f_2*t) + 4;
figure(1);
stem(t,s);

S = fft(s);
figure(2)
stem(0:length(S)-1,abs(S),"r");
grid on;
