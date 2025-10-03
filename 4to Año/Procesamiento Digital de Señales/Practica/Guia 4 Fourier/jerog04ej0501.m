t=0:1/50:1-1/50;
s=2*sin(2*pi*27*t);
figure(1);
stem(t,s);
s_fft = fft(s);
figure(2);
stem(abs(s_fft),"r");

## 1. ???

## 2. f_obs = f_m - f_s;

## 3. ???
