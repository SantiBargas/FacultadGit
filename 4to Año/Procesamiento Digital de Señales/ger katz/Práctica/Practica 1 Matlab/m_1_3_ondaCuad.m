%1-3)
%ti=0, tf=1, fm=100, fs=3, fi=0
function [t,y]=m_1_3_ondaCuad(ti,tf,fm,fs,fi)
T=1/fm;
t=ti:T:tf-T;
x=mod(2*pi*fs*t+fi,2*pi);
y = -1 .* (x>=pi) + 1 .* (x<pi);
plot(t,y)
end