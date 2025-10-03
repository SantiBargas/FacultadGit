function [x,t]=senoidal(ti,tf,fm,fs,fi)
  T=1/fm
  t=ti:T:tf-T
  x=sin(2*pi*fs*t+fi)
endfunction

