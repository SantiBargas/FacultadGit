%2. Cree un programa en Prolog que cuente la cantidad de veces que aparece un elemento en una
%lista.
%Ej.: contar(y, [a, b, c, a, d, e, a, f, a], Cantidad). => Cantidad = 0.
%Ej.: contar(a, [a, b, c, a, d, e, a, f, a], Cantidad). => Cantidad = 4.

contar(X,[],0).

contar(X,[X|Resto],Cantidad):- contar(X,Resto,Cantidad2), Cantidad is Cantidad2 + 1.

contar(X,[Y|Resto],Cantidad):- X\=Y, contar(X,Resto,Cantidad) .

