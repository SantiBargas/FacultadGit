function esUniforme = esMallaUniforme(nodos)
  #Método para los que no tienen huevos
  diferencias = diff(nodos);
  esUniforme = all(abs(diferencias - diferencias(1)) < 10e-8);

  #Solucion copada más rápida y menos robusta (tomo dos valores aleatorios del vector de nodos y los compara)
##  indiceNodo1 = randi(length(nodos)-1);
##  indiceNodo2 = indiceNodo1 + 1;
##  diferencia1 = nodos(indiceNodo2) - nodos(indiceNodo1);
##  indiceNodo3 = randi(length(nodos)-1);
##  indiceNodo4 = indiceNodo3 + 1;
##  diferencia2 = nodos(indiceNodo4) - nodos(indiceNodo3);
##  if (abs(diferencia1-diferencia2) < 0.000001 )
##      esUniforme = true;
##  else
##      esUniforme = false;
##  end
endfunction
