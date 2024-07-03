concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).

miembro(X,[X|_]):-!.
miembro(X,[_|R]):-miembro(X,R).

%ejemplo concatenar

%con concatenar
diferencia([],_,[]).
diferencia([L1|Resto1],L2,Resul):-not(miembro(L1,L2)),diferencia(Resto1,L2,Resul2),concatenar([L1],Resul2,Resul),!.
diferencia([_|Resto1],L2,Resul):-diferencia(Resto1,L2,Resul).

%poniendo en la cabecera
similitud([],_,0,[]).
similitud([P|R1],LsContiene,Cantidad,Resul):-miembro(P,LsContiene),similitud(R1,LsContiene,Aux,Resul),Cantidad is Aux +1,!.
similitud([P|R1],LsContiene,Cantidad,[P|Resul]):- similitud(R1,LsContiene,Cantidad,Resul).

eliminar_dup([],[]).
eliminar_dup([X|Resto],L2):- esmiembro(X,Resto),eliminar_dup(Resto,L2).
eliminar_dup([X|Resto],[X|L2]):- not(esmiembro(X,resto)),eliminar_dup(Resto,L2).

insertar(X,[],[X]). 
insertar(N,[X|R],[N|[X|R]]):- X > N. 
insertar(N,[X|R1],[X|R2]):- insertar(N,R1,R2). 
%insertar(3, [1, 2, 4, 5], Resultado). => Resultado = [1, 2, 3, 4, 5].

%ordenar
ordenar([],[]).
ordenar([Cab|Rest],Ord):-ordenar(Rest,Aux),insertar(Cab,Aux,Ord).

%aplanar
aplanar([],[]):-!.
aplanar([X|R],LS):-aplanar(X,L1),aplanar(R,L2),concatenar(L1,L2,LS),!.
aplanar(X,[X]).

%INVERTIR MATRIZ
pasar_primero([],[],[]):-!.
pasar_primero([[X|R]|RF1],[X|RC],[R|RF2]):-pasar_primero(RF1,RC,RF2).
inversa([[]|_],[]):-!.
inversa(S,[C|RC]):-pasar_primero(S,C,SSinPrimero),inversa(SSinPrimero,RC).
%inversa( [ [1,2,3],[4,5,6],[7,8,9] ] ,C2).


agregar_nuevo(E,[],[E]):-!.
agregar_nuevo(E,[E|R],[E|R]):-!.
agregar_nuevo(E,[X|R],[X|Lista]):- agregar_nuevo(E,R,Lista).

cantidad([],0):-!.
cantidad([X|Resto],Elementos):- cantidad(Resto,Elementos2), Elementos is Elementos2 + 1,!.
cantidad([X|Resto],Elementos):-cantidad(Resto,Elementos).

suma([],0).
suma([X|Resto],T):- suma(Resto,T2), T is T2 + X.
suma([X|Resto],T):-suma(Resto,T)




