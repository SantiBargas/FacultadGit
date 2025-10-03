function [t,y]=ondaCuad(ti,tf,fm,fs,fi)
T=1/fm;
t=ti:T:tf-T;
x=mod(2*pi*fs*t+fi,2*pi);
y = -1 .* (x>=pi) + 1 .* (x<pi);
plot(t,y)
end
