%6. Dado un diccionario en forma de lista de palabras, se quiere buscar una palabra cualquiera, para lo cual
%se deberá chequear que la misma pertenezca al diccionario. Si existe se debe devolver una lista de un
%elemento con la palabra buscada, si no existe, se debe devolver una lista con las alternativas a la
%palabra buscada y su valoración de semejanza.
%Las alternativas devueltas en caso de no existir la palabra en el diccionario, serán tomadas del mismo en
%virtud de la semejanza con la palabra buscada. Se tomarán como semejantes aquellas palabras cuyo
%valor de semejanza sea mayor a cero.
%Para el desarrollo de ésta segunda parte del programa, se puede usar el predicado predefinido
%atom_chars(C, L)” que toma un átomo (C) y lo transforma en una lista de literales (L):
%atom_chars(hola, L). --> L = [h, o, l, a].
%La definición del diccionario en principio es:
%dic([sanar, hola, sabana, sabalo, prueba, computadora, cartera, mate, termo, mesa, silla, sarna]).
%Ejemplos:
%buscar(hola, L). --> L = [hola]
%buscar(holo, L). --> L = [[hola, 2]]
%buscar(saban, L). --> L = [[sanar, 1], [sabana, 4], [sabalo, 2]]
miembro(X,[X|_]).
miembro(X,[_|R]):-miembro(X,R).
concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).

semejanza([],[],0):-!.
semejanza([_|Resto],[],S):- semejanza(Resto,[],Aux), S is Aux-1.
semejanza([],[_|Resto],S):- semejanza([],Resto,Aux), S is Aux-1.
semejanza([X|Resto1],[X|Resto2],S):-semejanza(Resto1,Resto2,Aux),S is Aux+1.
semejanza([_|Resto1],[_|Resto2],S):-semejanza(Resto1,Resto2,Aux),S is Aux-1.



dic([sanar, hola, sabana, sabalo, prueba, computadora, cartera, mate, termo, mesa, silla, sarna]).


buscar([],[]).
buscar(P,[P]):-dic(L),miembro(P,L).
buscar(P,R):-dic(L),buscar_aux(P,L,R).

buscar_aux(_,[],[]):-!.
buscar_aux(P,[L|Resto],[[L,S]|Resto2]):- atom_chars(P,E1),atom_chars(L,E2), semejanza(E1,E2,S),S>0,buscar_aux(P,Resto,Resto2),!.
buscar_aux(P,[L|Resto],R):- atom_chars(P,E1),atom_chars(L,E2), semejanza(E1,E2,S),S=<0,buscar_aux(P,Resto,R),!.




