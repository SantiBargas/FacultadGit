%4)
%ti=0,tf=1,A=1,fs=5Hz,Tm=0.00625s, t1=0
function [t,y]=m_4_sinusoidal(ti,tf,A,fs,Tm,t1)
t=ti:Tm:tf-Tm;
phi=-2*pi*fs*t1;
y=A*sin(2*pi*fs*t+phi);
plot(t,y);
end