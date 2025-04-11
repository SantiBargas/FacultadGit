function [coeficientes] = coeficientesFuncionesFormaCuadrangulos(p0, p1, p2, p3)

 #Este código es para definir funciones 2D (elementos finitos 2D Cuadrangulo)
 #Las funciones de forma tienen la forma: Ni(x,y) = ai + bi*x + ci*y + di*x*y

 #Cuatro puntos p0 p1 p2 y p3 representan los puntos del cuadrangulo
 #Se calcula con la matriz   M = [1, x0, y0, x0*y0; 1, x1, y1, x1*y1; 1, x2, y2, x2*y2; 1, x3, y3, x3*y3]
 # para N0 b0=(1 0 0 0) para N1 b1 = (0 1 0 0) para N2 b2=(0 0 1 0) para N3 b3=(0 0 0 1)

  % Coordenadas de los nodos
  x0 = p0(1); y0 = p0(2);
  x1 = p1(1); y1 = p1(2);
  x2 = p2(1); y2 = p2(2);
  x3 = p3(1); y3 = p3(2);

  % Matriz del sistema (con el término adicional x*y)
  M = [
    1, x0, y0, x0*y0;
    1, x1, y1, x1*y1;
    1, x2, y2, x2*y2;
    1, x3, y3, x3*y3;
  ];

  % Cálculo de los coeficientes para cada función de forma
  % N0
  b0 = [1; 0; 0; 0];
  coef0 = M \ b0;

  % N1
  b1 = [0; 1; 0; 0];
  coef1 = M \ b1;

  % N2
  b2 = [0; 0; 1; 0];
  coef2 = M \ b2;

  % N3
  b3 = [0; 0; 0; 1];
  coef3 = M \ b3;

  % Agrupamos los coeficientes en columnas
  coeficientes = [coef0, coef1, coef2, coef3];
endfunction
