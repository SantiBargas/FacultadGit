%11. Escribir un programa en Prolog que aplane una lista. El predicado aplanar/2 recibe una lista
%cuyos elementos pueden ser otras listas y debe retornar una lista con todos los elemento
%atómicos presentes.
%Ej.: aplanar([1, 2, 3], ListaPlana) . => ListaPlana = [1, 2, 3]
%Ej.: aplanar([1, 2, [3]], ListaPlana) . => ListaPlana = [1, 2, 3]
%Ej.: aplanar([1, [2, [3]]], ListaPlana) . => ListaPlana = [1, 2, 3]
concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).

aplanar([],[]).
aplanar([X|R],LS):-aplanar(X,L1),aplanar(R,L2),concatenar(L1,L2,LS).
aplanar(X,[X]).


aplanar2([],[]).
aplanar2([X|R],LS):-is_list(X),aplanar2(X,L1),aplanar2(R,L2),concatenar(L1,L2,LS).
aplanar2([X|R],[X|LS]):- aplanar2(R,LS),concatenar(L1,L2,LS).
