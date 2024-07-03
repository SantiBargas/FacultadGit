numero(0).
numero(1).
numero(2).
numero(3).
numero(4).
numero(5).
numero(6).
numero(7).
numero(8).
numero(9).

contar(X,[],0).
contar(X,[X|Resto],Cantidad):- contar(X,Resto,Cantidad2), Cantidad is Cantidad2 + 1.
contar(X,[Y|Resto],Cantidad):- X\=Y, contar(X,Resto,Cantidad).


encontrar_max_num([]).
encontrar_max_num([X|Resto]):-not(numero(X)),encontrar_max_num(Resto).
encontrar_max_num([X|Resto]):-numero(X),write("Lista no valdia").
encontrar_max([X|Resto],L):-encontrar_max_num([X|Resto]).