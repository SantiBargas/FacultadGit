%7. Escriba un programa en Prolog que dada una lista elimine todos los elementos duplicados de la
%misma.
%Ej.: eliminar_dup([1, 2, 3, 1, 4, 3, 5, 6], SinDup). => SinDup = [1, 2, 3, 4, 5, 6]

eliminar(_,[],[]).
eliminar(X,[X|Resto],Resultado):-eliminar(X,Resto,Resultado).
eliminar(X,[Y|Resto],[Y|Resultado]):- X\=Y,eliminar(X,Resto,Resultado).

eliminar_dup([],[]).
eliminar_dup([X|R],[X|Lfinal]):-eliminar(X,R,RSinRep),eliminar_dup(RSinRep,Lfinal).
