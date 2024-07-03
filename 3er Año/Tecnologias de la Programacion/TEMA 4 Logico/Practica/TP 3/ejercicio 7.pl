%Ejercicio 7 reemplazar(Elem,Reemp,Instancia,Cantidad,ListaElementos,Solucion).
miembro(X,[X|_]).
miembro(X,[_|R]):-miembro(X,R).



%reglas
reemplazar(_,_,_,_,[],[]):-!. %si es lista vacia, devuelve lista vacia.
reemplazar(E,_,_,_,Lista,Lista):-not(miembro(E,Lista)),write("El elemento no pertenece a la lista"),!.
reemplazar(_,_,I,_,Lista,Lista):-I<1,write("I Debe ser >= a 1"),!,fail. %el tercer elemento debe ser  >=1, para que corte ponemos lo contrario y devolvemos la lista
reemplazar(_,_,_,C,Lista,Lista):- C < 1 , C \= -1,write("La cantidad de reemplazos debe ser -1 o mayor o igual a 1"),!,fail.  

reemplazar(_,_,_,_,[],[]). %si es lista vacia, devuelve lista vacia.
reemplazar(_,_,_,0,[],[]).

reemplazar(E,R,I,C,[E|Resto],[E|Solucion]):- I>1,Iaux is -1 , reemplazar(E,R,Iaux,C,Resto,Solucion). 
reemplazar(E,R,I,C,[X|Resto],[X|Solucion]):-E\=X , reemplazar(E,R,I,C,Resto,Solucion). 
reemplazar(E,R,1,C,[E|Resto],[R|Solucion]):- Caux is C-1 ,reemplazar(E,R,1,Caux,Resto,Solucion).
reemplazar(E,R,1,C,[X|Resto],[X|Solucion]):-E\=X, reemplazar(E,R,1,C,Resto,Solucion).


%reemplazar(E,R,I,-1,[E|Resto],[E|Solucion]):- I>1,Iaux is -1 , reemplazar(E,R,Iaux,-1,Resto,Solucion). 
reemplazar(E,R,I,C,[E|Resto],[E|Solucion]):- I>1,Iaux is -1 , reemplazar(E,R,Iaux,C,Resto,Solucion). %el primer elemento de la lista coincide con E

reemplazar(E,R,I,-1,[X|Resto],[X|Solucion]):- E\=X , reemplazar(E,R,I,-1,Resto,Solucion). 
%reemplazar(E,R,I,C,[X|Resto],[E|Solucion]):- E\=X , reemplazar(E,R,I,C,Resto,Solucion). 

reemplazar(E,R,1,-1,[E|Resto],[R|Solucion]):-reemplazar(E,R,1,-1,Resto,Solucion).

reemplazar(E,R,1,-1,[X|Resto],[X|Solucion]):-E\=X, reemplazar(E,R,1,-1,Resto,Solucion).

