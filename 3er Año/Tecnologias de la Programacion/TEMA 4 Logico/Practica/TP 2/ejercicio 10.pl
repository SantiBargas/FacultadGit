
insertar(X,[],[X]).
insertar(E,[X|R],[E|[X|R]]):- X > E. 
insertar(E,[X|Resto1],[X|Resto2]):- insertar(E,Resto1,Resto2).


%10. Escriba un programa en Prolog que recursivamente ordene una lista de números enteros.
%Ej.: ordenar([2, 4, 3, 1], ListaOrdenada). => ListaOrdenada = [1, 2, 3, 4].

ordenar([],[]).
ordenar([X|Resto],Lista):-ordenar(Resto,Aux),insertar(X,Aux,Lista).



