%6. Escribir un programa en Prolog que reciba dos listas de números, verifiquen que sean de la
%misma longitud, y luego retorne una lista con la suma elemento a elemento de ambas listas.
%Ej.: suma_lista([1, -2, 3, -4], [2, 3, 1, 4], ListaSuma). => ListaSuma = [3, 1, 4, 0].

concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).


suma_lista([],[],[]).
suma_lista([X|Resto1],[Y|Resto2],ListaSuma):-suma_lista(Resto1,Resto2,L2), Aux is X+Y, concatenar([Aux],L2,ListaSuma).

