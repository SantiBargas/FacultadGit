tablero(1,1). tablero(1,2). tablero(1,3). tablero(1,4). tablero(1,5). tablero(1,6). tablero(1,7). tablero(1,8).
tablero(2,1). tablero(2,2). tablero(2,3). tablero(2,4). tablero(2,5). tablero(2,6). tablero(2,7). tablero(2,8).
tablero(3,1). tablero(3,2). tablero(3,3). tablero(3,4). tablero(3,5). tablero(3,6). tablero(3,7). tablero(3,8).
tablero(4,1). tablero(4,2). tablero(4,3). tablero(4,4). tablero(4,5). tablero(4,6). tablero(4,7). tablero(4,8).
tablero(5,1). tablero(5,2). tablero(5,3). tablero(5,4). tablero(5,5). tablero(5,6). tablero(5,7). tablero(5,8).
tablero(6,1). tablero(6,2). tablero(6,3). tablero(6,4). tablero(6,5). tablero(6,6). tablero(6,7). tablero(6,8).
tablero(7,1). tablero(7,2). tablero(7,3). tablero(7,4). tablero(7,5). tablero(7,6). tablero(7,7). tablero(7,8).
tablero(8,1). tablero(8,2). tablero(8,3). tablero(8,4). tablero(8,5). tablero(8,6). tablero(8,7). tablero(8,8).

reina(2, 3).
alfil(6, 3).
torre(8, 5).

come_torre(F,_,F,_).
come_torre(_,C,_,C).
come_alfil(F1,C1,F2,C2):- S is abs(F2-F1), S2 is abs(C2-C1), S=S2.

amenaza(F,C,_):-not(tablero(F,C)),!,write('Debe ingresar una posicion del tablero valida'),fail.
amenaza(F,C,Res):-tablero(F,C),torre(F2,C2),come_torre(F,C,F2,C2),Res = torre(F2,C2).
amenaza(F,C,Res):-tablero(F,C),alfil(F2,C2),come_alfil(F,C,F2,C2),Res = alfil(F2,C2).
amenaza(F,C,Res):-tablero(F,C),alfil(F2,C2),torre(F3,C3),reina(F4,C4),come_alfil(F,C,F2,C2),come_torre(F,C,F3,C3),Res = reina(F4,C4).