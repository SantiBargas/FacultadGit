%1-1)
%ti=0, tf=1, fm=100, fs=1, fi=0
function [t,x]=m_1_1_senoidal(ti,tf,fm,fs,phi)
T=1/fm;
t=ti:T:tf-T;
x=sin(2*pi*fs*t+phi);
plot(t,x);
end