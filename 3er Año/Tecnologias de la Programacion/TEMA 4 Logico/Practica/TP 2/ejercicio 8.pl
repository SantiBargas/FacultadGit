%8. Escribir un programa en Prolog que recorra un �rbol binario y determine la profundidad del
%mismo.
%La representaci�n del �rbol ser� una lista con el siguiente formato: [I, N, D] en donde:
%? I es una lista que representa el sub�rbol de la rama izquierda
%? N es el valor del nodo ra�z
%? D es una lista que representa el sub�rbol de la rama derecha
%As� el �rbol:
%           a
%          /  \
%          b  e
%        / \  /
%       c d  f
%estar�a representado por [[[c], b, [d]], a, [[], e, [f]]]
%Las ramas vac�as se representan con una lista vac�a, y las hojas como una lista de un solo
%elemento.
%Ej.: profundidad([[[c], b, [d]], a, [[], e, [f]]], Profundidad). => Profundidad = 3.


mayor(X,Y,X):-X>Y.
mayor(X,Y,Y):-Y>=X.
profundidad([],0).
profundidad([_],1).
profundidad([AI,_,AD],P):-profundidad(AI,P1),profundidad(AD,P2),mayor(P1,P2,PM),P is PM+1.