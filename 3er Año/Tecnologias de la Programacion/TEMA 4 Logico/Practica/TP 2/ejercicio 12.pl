%12. El siguiente programa en Prolog calcula las permutaciones de los elementos de una lista.
%a. Ejecute el mismo y escriba el resultado obtenido para per([1, 2, 3], L).
%b. Explique en sus propios términos cuál es la lógica que utiliza el programa para
%obtener las permutaciones.
ins(X, L, [ X | L ]).
ins(X, [ Y | L1 ], [ Y | L2 ]) :- ins(X, L1, L2).
per([],[]).
per([ X | L ], Lp) :- per(L, L1), ins(X, L1, Lp).


%a L = [1, 2, 3]
%L = [2, 1, 3]
%L = [2, 3, 1]
%L = [1, 3, 2]
%L = [3, 1, 2]
%L = [3, 2, 1]
%false

%b lo primero que hace es vacia la lista con la recursion, despues agrega el ultimo