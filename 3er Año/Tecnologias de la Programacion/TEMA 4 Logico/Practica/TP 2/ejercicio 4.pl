%4. Escriba un programa en Prolog que dada una lista de números enteros, calcule el resultado de
%sumar dichos números.
%Ej.: suma([1, 2, 3], X). => X = 6.


cantidad([],0).
cantidad([X|Resto],Elementos):- cantidad(Resto,Elementos2), Elementos is Elementos2 + 1.
cantidad([X|Resto],Elementos):-cantidad(Resto,Elementos).

suma([],0).
suma([X|Resto],T):- suma(Resto,T2), T is T2 + X.
suma([X|Resto],T):-suma(Resto,T)