%8. Escribir un programa en Prolog que recorra un árbol binario y determine la profundidad del
%mismo.
%La representación del árbol será una lista con el siguiente formato: [I, N, D] en donde:
%? I es una lista que representa el subárbol de la rama izquierda
%? N es el valor del nodo raíz
%? D es una lista que representa el subárbol de la rama derecha
%Así el árbol:
%           a
%          /  \
%          b  e
%        / \  /
%       c d  f
%estaría representado por [[[c], b, [d]], a, [[], e, [f]]]
%Las ramas vacías se representan con una lista vacía, y las hojas como una lista de un solo
%elemento.
%Ej.: profundidad([[[c], b, [d]], a, [[], e, [f]]], Profundidad). => Profundidad = 3.


mayor(X,Y,X):-X>Y.
mayor(X,Y,Y):-Y>=X.
profundidad([],0).
profundidad([_],1).
profundidad([AI,_,AD],P):-profundidad(AI,P1),profundidad(AD,P2),mayor(P1,P2,PM),P is PM+1.