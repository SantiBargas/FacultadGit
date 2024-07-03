%7. Escriba un programa en Prolog que represente el cuerpo de conocimiento con los distintos platos
%de un restaurante: entrada, plato principal y postre.
%Cree el cuerpo de conocimiento con tres ejemplos de cada uno.
%Por último cree un predicado “carta/3” que como resultado combina todos los posibles platos,
%en donde el primer argumento corresponde a las entradas, el segundo a los platos principales y
%el tercero a los postres. ¿Cuántos resultados debería retornar?
%Ejemplo:
%?- carta(X, Y, Z).
%X = ensalada, Y = lomo a la pimienta, Z = flan;

entrada(empanadas).
entrada(queso).
entrada(salame).
platoprincipal(milanesa).
platoprincipal(asado).
platoprincipal(hamburguesa).
postre(helado).
postre(chocolate).
postre(torta).

carta(X,Y,Z):-entrada(X),platoprincipal(Y),postre(Z).
