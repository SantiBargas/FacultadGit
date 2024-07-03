
reina(2, 3).
alfil(6, 3).
torre(8, 5).

tablero(F,C):- F =< 8,C =< 8.

%F1 Y C1 ES LA POSICION DE LA FICHA
come_torre(F,C,_,C1):-torre(F,C) , C==C1.
come_torre(F,C,F1,_):-torre(F,C) , F==F1.

come_alfil(F,C,F1,C1):- S is abs(F1-F), S2 is abs(C1-C), S=S2.


amenaza(F,C,R):-tablero(F,C),alfil(X,Y),come_alfil(X,Y,F,C),R = alfil(X,Y).
amenaza(F,C,R):-tablero(F,C),torre(X,Y),come_torre(X,Y,F,C),R = torre(X,Y).

amenaza(F,C,R):-tablero(F,C),torre(X,Y),reina(Z,W),come_torre(X,Y,F,C),R = reina(Z,W).
amenaza(F,C,R):-tablero(F,C),alfil(X,Y),reina(Z,W),come_alfil(X,Y,F,C),R = reina(Z,W).
%amenaza(4, 5, R).
