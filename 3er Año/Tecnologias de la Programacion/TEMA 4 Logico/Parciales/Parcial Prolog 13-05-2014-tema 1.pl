
sumar([], 0) :- !.
sumar([X|L], V) :- sumar(L, V1), V is X + V1.
%sumar([1,2,3],R).

caminos([X], [X]):-!.
caminos([X|L], [X|L1]) :- member(C, L), caminos(C, L1).
%caminos([1, [1, [2], [7]]],L).


mayor_valor([], 0) :- !.
mayor_valor([X|Resto], Vm) :- sumar(X,V), mayor_valor(Resto, V1), Vm is max(V, V1).
%mayor_valor( [ [1,2,1],[1,1,7],[1,3,5] ], L).


caminos_max_aux([R|Resto],Vm,L):-sumar(R,X),X\=Vm,caminos_max_aux(Resto,Vm,L).
caminos_max_aux([R|Resto],Vm,L):-sumar(R,X),X==Vm,caminos_max_aux(Resto,Vm,L).
caminos_max(Arbol,Lista):-caminos(Arbol,R),mayor_valor(R,Vm),caminos_max_aux(R,Vm,L).

%caminos_max([1, [1, [2], [7]], [2, [1], [4]], [3, [2], [5]]], L).
