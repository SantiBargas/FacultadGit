function [coeficientes] = coeficientesFuncionesFormaCuad(x0,x1,x2)
  M = [x0^2,x0,1; x1^2,x1,1; x2^2,x2,1];
  #N0
  b0 = [1,0,0]';
  coef0 = M\b0;
  #N1
  b1 = [0,1,0]';
  coef1 = M\b1;
  #N2
  b2 = [0,0,1]';
  coef2 = M\b2;
  coeficientes = [coef0,coef1,coef2];
endfunction
