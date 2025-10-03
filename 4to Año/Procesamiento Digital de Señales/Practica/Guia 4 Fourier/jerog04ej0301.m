f_m=100;
T_m=1/f_m;
t=0:T_m:1-T_m;

s = sin(2*pi*10*t);
N = length(s);
k = 0:length(s)-1;
s_f = fft(s);

stem(t,s);

s_f = s_f .* e.^(((i*2*pi*10).*k)/N);

s_ret = ifft(s_f);

hold on
stem(t,s_ret);

