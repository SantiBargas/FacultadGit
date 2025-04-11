#Funcion que devuelve la matriz de difusion por cordenadas cartesianas
function [localK] = matriz_difusion(nodes,kx,ky)
  pkg load symbolic

  syms x y

  localK = [];
  if length(nodes) == 3
    #Calculo las funciones de forma
    [Ns] = funciones_forma(nodes);

    #Calculo la matriz B derivando las funciones de forma
    B = [diff(Ns(1),x) diff(Ns(2),x) diff(Ns(3),x);
        diff(Ns(1),y) diff(Ns(2),y) diff(Ns(3),y)];

    #Calculo el Jacobiano
    J = [ nodes(2, :) - nodes(1, :);...
            nodes(3, :) - nodes(1, :)];

    #Calculo la matricita K
    k = [kx 0;0 ky];

    #Calculo el area del triangulo
    Area = 1/2*abs(nodes(1,1)*(nodes(2,2)-nodes(3,2)) + nodes(2,1)*(nodes(3,2)-nodes(1,2)) + nodes(3,1)*(nodes(1,2)-nodes(2,2)));

    #Calculo la matriz local K
    localK = B'*x*B*det(J)*Area
  elseif length(nodes) == 4
    #Calculo las funciones de forma
    [Ns] = funciones_forma(nodes);

    B = [diff(Ns(1), x) diff(Ns(2), x) diff(Ns(3), x) diff(Ns(4), x);
     diff(Ns(1), y) diff(Ns(2), y) diff(Ns(3), y) diff(Ns(4), y)];

    # Calculo el Jacobiano para el cuadrilátero (usando una matriz 2x2)
    J = [nodes(2,1) - nodes(1,1), nodes(3,1) - nodes(1,1);
         nodes(2,2) - nodes(1,2), nodes(3,2) - nodes(1,2)];

    # Extraemos las coordenadas de los nodos
    x1 = nodes(1, 1); y1 = nodes(1, 2);
    x2 = nodes(2, 1); y2 = nodes(2, 2);
    x3 = nodes(3, 1); y3 = nodes(3, 2);
    x4 = nodes(4, 1); y4 = nodes(4, 2);

    # Calculamos el área de los dos triángulos
    area1 = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    area2 = 0.5 * abs(x1*(y3 - y4) + x3*(y4 - y1) + x4*(y1 - y3));

    # Área total del cuadrilátero
    area = area1 + area2;

    k = [kx,0;0,ky];

    localK = B'*k*B*det(J)*area

  endif

endfunction
