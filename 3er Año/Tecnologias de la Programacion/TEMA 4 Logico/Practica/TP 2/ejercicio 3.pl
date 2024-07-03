
%3. Escribir un programa en Prolog “cantidad/2” que reciba como primer parámetro una lista de
%números y unifique el segundo con la cantidad de elementos de dicha lista.
%Ej.: cantidad([a, b, c], Elementos). => Elementos = 3.


cantidad([],0).
cantidad([X|Resto],Elementos):- cantidad(Resto,Elementos2), Elementos is Elementos2 + 1.
cantidad([X|Resto],Elementos):-cantidad(Resto,Elementos).