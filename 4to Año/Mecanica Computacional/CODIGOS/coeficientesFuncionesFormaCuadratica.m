function [coeficientes] = coeficientesFuncionesFormaCuadratica(x0,x1,x2)
 #Este código es para definir funciones de una dimension (elementos finitos barras 1D)
 #forma cuadratica en elementos.
 #Las funciones de forma tienen la forma: Ni(x,y) = ai*x^2 + bi*x + ci

 #Tres puntos p0 p1 y p2 representan los puntos del triangulo
 #Se calcula con la matriz M=[x0^2 x0 1 ;x1^2 x1 1; x2^2 x2 1]
 # para N0 b0=(1 0 0) para N1 b1 = (0 1 0) para N2 b2=(0 0 1)

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
