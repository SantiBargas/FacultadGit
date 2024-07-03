%5. Escriba un programa en Prolog que, dada una lista de números enteros, retorne otra lista solo
%con los números positivos de la misma.
%Ej.: positivos([1, -2, 3, -4], ListaPositivos). => ListaPositivos = [1, 3].

concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).


positivos([],[]).
positivos([X|Resto],ListaPositivos):- X>0 , positivos(Resto,L2), concatenar([X],L2,ListaPositivos).
positivos([X|Resto],ListaPositivos):- X=<0 , positivos(Resto,ListaPositivos).


