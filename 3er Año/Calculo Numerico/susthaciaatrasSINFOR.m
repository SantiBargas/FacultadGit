function [x]= susthaciaatrasSINFOR(A)
  x=A(:,end); %Creo x como vector de la ultima columna de A
  n=length(x); %Saco cuandos filas tengo
  x(n)= x(n)/A(n,n); %Divido el ultimo termino independiente por el ultimo valor de la matris
  s=x;%copio vector columna de todos los coef independientes
  for i=n-1 :-1: 1 %Recorro las filas
    %  s(i) = s(i) - (A(i,i+1:n) * x(i+1:n)); %Guardo en s los coef indep. menos todos los valores multiplicados por las soluciones ya obtenidas
      x(i) = (s(i) - (A(i,i+1:n) * x(i+1:n)))/A(i,i); %Guardo la solucion dividiendo el numero por el coef de esa sol

  endfor
endfunction
