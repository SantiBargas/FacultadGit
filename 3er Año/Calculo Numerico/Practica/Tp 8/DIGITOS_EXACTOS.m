%Ej6TP8

h=0.01;
%L=(5-0)/h;
L=2;
[xDFR,yDFR]=dif_fin_rob(f,inter,y0,rob,L)



for i=1:100
  L = L*2;
  [xDFR,yDFR1]=dif_fin_rob(f,inter,y0,rob,L)

     if ( abs(yDFR1(end) - yDFR(end) ) < 1e-5)  %si pide 4 digitos ponemos 1e-5
      yDFR=yDFR1;
      break
    endif
  yDFR=yDFR1;
endfor
