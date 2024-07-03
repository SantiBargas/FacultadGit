
%FUNCION Q VALIDA Q NO HAY REPETIDOS

miembro(X,[X|_]).
miembro(X,[_|R]):-miembro(X,R).
%Union
union([],C2,C2):-!.
union(C1,[],C1):-!.
union([X|R],C2,[X|L]):-not(member(X,C2)),union(R,C2,L),!.
union([_|R],C2,[X|L]):-union(R,C2,L).

%interseccion
interseccion([],_,[]):-!.
interseccion(_,[],[]):-!.
interseccion([X|R],C2,[X|L]):-miembro(X,C2),interseccion(R,C2,L),!.
interseccion([_|R],C2,L):-interseccion(R,C2,L).

%DIFERENCIA

diferencia([],_,[]):-!.
diferencia(C1,[],C1):-!.
diferencia([X|R],C2,[X|L]):-not(miembro(X,C2)),diferencia(R,C2,L),!.
diferencia([_|R],C2,L):-interseccion(R,C2,L).


%diferencia(['Barreras','A pesar de todo','Otro dia para matar','Yo soy sam'],['Barreras','A pesar de todo','Quizas para siempre','La casa del lago'],L).