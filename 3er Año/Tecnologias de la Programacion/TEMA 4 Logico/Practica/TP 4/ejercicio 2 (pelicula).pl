vio(maria,['Barreras','A pesar de todo','Quizas para siempre','Otro dia para matar','La casa del lago','Bruja']).
vio(jose,['Misterio a bordo','The perfection','Otro dia para matar','Barreras','Yo soy sam','Inspection']).
vio(pedro,['Barreras','A pesar de todo','Otro dia para matar','Yo soy sam']).
usuario(maria).
usuario(jose).
usuario(pedro).

concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).
miembro(X,[X|_]).
miembro(X,[_|R]):-miembro(X,R).


diferencia([],_,[]).
diferencia([L1|Resto1],L2,Resul):-not(miembro(L1,L2)),diferencia(Resto1,L2,Resul2),concatenar([L1],Resul2,Resul),!.
diferencia([_|Resto1],L2,Resul):-diferencia(Resto1,L2,Resul).
%diferencia(['Barreras','A pesar de todo','Quizas para siempre','La casa del lago'],['Barreras','A pesar de todo','Otro dia para matar','Yo soy sam'],L).

semejanza([],_,0):- !.
semejanza([P|R1],LsContiene,Cantidad):- miembro(P,LsContiene),semejanza(R1,LsContiene,Aux), Cantidad is Aux + 1,!.
semejanza([P|R1],LsContiene,Cantidad):- not(miembro(P,LsContiene)), semejanza(R1,LsContiene,Cantidad). 
%semejanza(['Barreras','A pesar de todo','Quizas para siempre','La casa del lago'],['Barreras','A pesar de todo','Otro dia para matar','Yo soy sam'],S).
%= ['Quizas para siempre','La casa del lago'].


%netflix_aux(3,['Barreras','A pesar de todo','Otro dia para matar','Yo soy sam'],['Barreras','A pesar de todo','Quizas para siempre','La casa del lago','Bruja'],L).
netflix_aux(S,X,Y,L):-S>2,diferencia(Y,X,L).
netflix(Usuario,L):-usuario(U2),vio(Usuario,X),Usuario\=U2,vio(U2,Y),semejanza(X,Y,S),netflix_aux(S,X,Y,L).
%netflix(pedro,L).


