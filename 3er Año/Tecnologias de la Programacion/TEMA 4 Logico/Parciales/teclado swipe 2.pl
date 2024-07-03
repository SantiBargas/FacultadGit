dic([hola,hoja,hija]).


%FUNCION Q VALIDA Q SEAN TODAS LETRAS
swype_atom([]).
swype_atom([X|_]):-not(atom(X)),!,fail.
swype_atom([X|Resto]):-atom(X),swype_atom(Resto).

%Funcion para ver si un elemento esta en una lista:
miembro(X,[X|_]):-!.
miembro(X,[_|R]):-miembro(X,R).

%Funcion para ver si todos los elementos de una lista estan en una lista
miembro_l([],_):-!.
miembro_l([X|R1],L):-miembro(X,L),miembro_l(R1,L).


swype_aux(_,[],[]):-!.
swype_aux(L,[X|R1],[X|R2]):-atom_chars(X,LC),miembro_l(LC,L),swype_aux(L,R1,R2),!.
swype_aux(L,R1,[_|R2]):-swype_aux(L,R1,R2).

swype(L,LF):-swype_atom(L),dic(Dic),swype_aux(L,LF,Dic).

%swype([h,i,o,l,k,j,h,g,f,1,s,a],R).
%swype([h,i,o,l,k,j,h,g,f,d,s,a],R).
