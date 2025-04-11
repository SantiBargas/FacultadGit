function [coeficientes] = coeficientesFuncionesFormaLin(p0,p1,p2)

  x0 = p0(1);
  y0 = p0(2);
  x1 = p1(1);
  y1 = p1(2);
  x2 = p2(1);
  y2 = p2(2);

  M = [1 x0 y0; 1 x1 y1;1 x2 y2];
  #N0
  b0 = [1,0,0]';
  coef0 = M\b0;
  #N1
  b1 = [0,1,0]';
  coef1 = M\b1;
  #N2
  b2 = [0,0,1]';
  coef2 = M\b2;
  coeficientes = [coef0,coef1,coef2];#se guardan por columna, para obtener el primero
                                     #hacemos coeficientes(:,1)
endfunction
