%1-2)
%ti=0, tf=1, fm= 100, fs=3
function [t,y]=m_1_2_sinc(ti,tf,fm,fs)
T=1/fm;
t=ti:T:tf-T;
x=2*pi*fs*t;
y = (sin(x)./x) .* (x~=0) + 1 .* (x==0);
plot(x,y);
end