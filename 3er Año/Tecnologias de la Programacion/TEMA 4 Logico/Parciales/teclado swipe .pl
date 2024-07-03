dic(hola).
dic(hoja).
dic(hija).
dic(ola).
dic(lo).

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
numero(10).

miembro(X,[X|_]).
miembro(X,[_|R]):-miembro(X,R).


swype_num([]):-!.
swype_num([X|_]):-numero(X),write("La lista no debe contener numeros"),!,fail.
swype_num([_|Resto]):-swype_num(Resto).
swype([X|Resto],Resul):-swype_num([X|Resto]),dic(Y),atom_chars(Y,E1),swype_aux2([X|Resto],E1,Y,Resul).  %Verificacion de que la lista no contega numeros

swype_aux2(_,[],Y,Y):-!.
swype_aux2([X|Resto],[E1|_],_,_):-not(miembro(E1,[X|Resto])),!.
swype_aux2([X|Resto],[E1|Resto2],Y,Resul):-miembro(E1,[X|Resto]),swype_aux2([X|Resto],Resto2,Y,Resul).


%[h,i,o,l,k,j,h,g,f,1,s,a] [h,o,l,a] , hola , R


%swype([h,i,o,l,k,j,h,g,f,1,s,a],R).
%swype([h,i,o,l,k,j,h,g,f,d,s,a],R).
%swype([h,o,l,a,j,i],R).
%atom_chars(P,E1).
