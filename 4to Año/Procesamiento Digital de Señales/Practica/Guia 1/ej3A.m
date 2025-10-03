function [Tm,fm,fs,fi]=ej3A(N1,N2)

  TiempoTotal = 0.1;
  A=3;

  Tm = TiempoTotal / (N1);
  fm = 1/Tm;
  fs = fm/N2;

  #T1 retardo temporal
  t1=0.006;
  fi=-2*pi*20*5/8*0.01;

  [t,x]=ej3(fm,fs,A,fi);


endfunction

#Le pasamos la cant de muestras total y la cantidad de muestras por ciclo
#[Tm,fm,fs,fi]=ej3A(80,40)
