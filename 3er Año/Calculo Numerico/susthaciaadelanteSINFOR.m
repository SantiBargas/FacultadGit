function[x]=susthaciaadelanteSINFOR(A)
  x=A(:,end); %Creo x como vector de la ultima columna de A
  n=length(x); %Saco cuantas filas tengo
  x(1)= x(1)/A(1,1); %Divido el primer termino independiente por primer valor de la matriz
  s=x;%copio vector columna de todos los coef independientes
  for i=2 :1: n %Recorro las filas desde la fila 2 hasta n
    %  s(i) = ; %Guardo en s los coef indep. menos todos los valores multiplicados por las soluciones ya obtenidas
      x(i) = (s(i) - (A(i,1:i-1) * x(1:i-1)))/A(i,i); %Guardo la solucion dividiendo el numero por el coef de esa solucion

  endfor
endfunction
