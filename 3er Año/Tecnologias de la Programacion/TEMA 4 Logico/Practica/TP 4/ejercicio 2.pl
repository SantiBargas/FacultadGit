vio(maria,['Barreras','A pesar de todo','Quizas para siempre','La casa del lago','Bruja']).
vio(jose,['Misterio a bordo','The perfection','Otro dia para matar','Barreras','Yo soy sam','Inspection']).
vio(pedro,['Barreras','A pesar de todo','Otro dia para matar','Yo soy sam']).
usuarios([jose,maria,pedro]).

concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).
miembro(X,[X|_]).
miembro(X,[_|R]):-miembro(X,R).

semejanza([],_,0):- !.
semejanza([P|R1],LsContiene,Cantidad):- miembro(P,LsContiene),semejanza(R1,LsContiene,Aux), Cantidad is Aux + 1,!.
semejanza([P|R1],LsContiene,Cantidad):- not(miembro(P,LsContiene)), semejanza(R1,LsContiene,Cantidad). 

%semejanza(['Barreras','A pesar de todo','Otro dia para matar','Yo soy sam'],['Barreras','A pesar de todo','Quizas para siempre','La casa del lago'],S).

pelis_no_vio(_,[],_):-!.
pelis_no_vio(L1,[L2|Resto],[Resul|L2]):-not(miembro(L2,L1)),pelis_no_vio(L1,Resto,Resul).
pelis_no_vio(L1,[L2|Resto],Resul):-miembro(L2,L1),pelis_no_vio(L1,Resto,Resul).

recomendacion_aux(X,S1,S2,Lista):-S2<2,S1<2,write('No existen recomendaciones').
recomendacion_aux(X,S1,S2,Lista):- S2>2,S1<2,vio(jose,Z),pelis_no_vio(X,Z,Lista).
recomendacion_aux(X,S1,S2,Lista):- S1>2,S2<2,vio(maria,Y),pelis_no_vio(X,Y,Lista).
recomendacion_aux(X,S1,S2,Lista):- S1>2,S2>2,vio(maria,Y),vio(jose,Z),pelis_no_vio(X,Y,Lista1),pelis_no_vio(X,Y,Lista1),pelis_no_vio(X,Z,Lista2),concatenar(Lista1,Lista2,Lista3).
recomendacion(Usuario,Lista):-vio(Usuario,X),vio(maria,Y),vio(jose,Z),semejanza(X,Y,S1),semejanza(X,Z,S2),recomendacion_aux(X,S1,S2,Lista).

%pelis_no_vio(['Barreras','A pesar de todo','Otro dia para matar','Yo soy sam'],['Barreras','A pesar de todo','Quizas para siempre','La casa del lago'],L3).
%recomendacion(pedro,Lista).
