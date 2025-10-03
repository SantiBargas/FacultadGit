%3)
%ti=0,tf=0.1
%A=3, fs = 20Hz = 1/0.05s
%Tm=0.05s/40 muestras=0.00125s
%t1=0.01s - 3*0.00125s = 0.00625s

function [t,x]=m_3_sinusoidal(ti,tf,A,fs,Tm,t1)
t=ti:Tm:tf-Tm;
phi=-2*pi*fs*t1;
x=A*sin(2*pi*fs*t+phi);
stem(t,x);
end