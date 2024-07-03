


butacas(F,C):- F =< 8 , C=<16.
ocupadas([3,3],[3,4]).
pasillo(F,C):- F =<1 , F =\= 9 , C=7.
pasillo(F,C):- F =<1 , F =\= 9 , C=10.

precio1([1,2,3,8,9]).
precio2([4,5,6,7]).

miembro(X,[X|_]):-!.
miembro(X,[_|R]):-miembro(X,R).

encontrar_butaca_no_pasillo(Cant,Cant,_,_,_,[]):-!.  % corta si el contador es igual a las butacas buscadas es el caso correcto
encontrar_butaca_no_pasillo(_,_,_,16,_,_):-!. %corta si la columna llego a su fin 
encontrar_butaca_no_pasillo(Cant,Cont,F,C,0,[["fila",F,"butaca",C]|Resul]):-not(ocupadas(F,C)),butacas(F,C),not(pasillo(F,C)),C2 is C+1, Cont2 is Cont + 1 , encontrar_butaca_no_pasillo(Cant,Cont2,F,C2,1,Resul),!. %Encontramos butaca, activamos la bandera e incrementamos el contador
encontrar_butaca_no_pasillo(Cant,Cont,F,C,1,[["fila",F,"butaca",C]|Resul]):- not(ocupadas(F,C)),butacas(F,C),not(pasillo(F,C)),C2 is C+1 , Cont2 is Cont + 1 , encontrar_butaca_no_pasillo(Cant,Cont2,F,C2,1,Resul),!. %si es butaca y no esta en el pasillo Y no esta ocupada seguimos e incrementamos el contador
encontrar_butaca_no_pasillo(Cant,_,F,C,1,[["fila",F,"butaca",C]|Resul]):- butacas(F,C),pasillo(F,C),C2 is C+1 , encontrar_butaca_no_pasillo(Cant,0,F,C2,0,Resul),!. %si esta en el pasillo cortamos la bandera y reiniciamos el cont
encontrar_butaca_no_pasillo(Cant,_,F,C,1,Resul):- butacas(F,C),ocupadas(F,C),encontrar_butaca_no_pasillo(Cant,0,F,C,0,Resul). %si estan ocupadas cortamos la bandera y no concatenamos y reiniciamos el cont
%encontrar_butaca_no_pasillo(4,0,1,1,0,R).
%encontrar_butaca_no_pasillo(3,0,3,1,0,R).


%para el pasillo es lo mismo que sin pasillo pero una vez devuelta la lista debemos chequear si la ultima esta en el pasillo

encontrar_butaca_pasillo(Cant,Cant,_,_,_,[]):-!.  % corta si el contador es igual a las butacas buscadas es el caso correcto
encontrar_butaca_pasillo(_,_,_,16,_,_):-!. %corta si la columna llego a su fin 
encontrar_butaca_pasillo(Cant,Cont,F,C,0,[["fila",F,"butaca",C]|Resul]):-not(ocupadas(F,C)),butacas(F,C),C2 is C+1, Cont2 is Cont + 1 , encontrar_butaca_no_pasillo(Cant,Cont2,F,C2,1,Resul),!. %Encontramos butaca, activamos la bandera e incrementamos el contador
encontrar_butaca_pasillo(Cant,Cont,F,C,1,[["fila",F,"butaca",C]|Resul]):- not(ocupadas(F,C)),butacas(F,C),C2 is C+1 , Cont2 is Cont + 1 , encontrar_butaca_no_pasillo(Cant,Cont2,F,C2,1,Resul),!. %si es butaca Y no esta ocupada seguimos e incrementamos el contador
encontrar_butaca_pasillo(Cant,Cont,F,C,1,[["fila",F,"butaca",C]|Resul]):-butacas(F,C),not(ocupadas(F,C)),C2 is C+1 ,Cont is Cant-1,Cont2 is Cont + 1 ,pasillo(F,C),encontrar_butaca_pasillo(Cant,Cont2,F,C2,1,Resul),!. %si el contador es igual a cantidad - 1 debemos chequear que la butaca este en el pasillo y si esta seguimos la recursion
encontrar_butaca_pasillo(Cant,Cont,F,C,1,[["fila",F,"butaca",C]|Resul]):-butacas(F,C),not(ocupadas(F,C)),Cont is Cant-1,not(pasillo(F,C)),encontrar_butaca_pasillo(Cant,0,F,C,0,Resul),!. %si el contador es igual a cantidad - 1 debemos chequear que la butaca este en el pasillo y si no esta cortamos, reiniciamos contador y bandera
encontrar_butaca_pasillo(Cant,_,F,C,1,Resul):- butacas(F,C),ocupadas(F,C),encontrar_butaca_no_pasillo(Cant,0,F,C,0,Resul). %si estan ocupadas cortamos la bandera y no concatenamos y reiniciamos el cont
%encontrar_butaca_pasillo(1,0,1,1,0,R).

encontrar_butaca2(_,9,_,_,_). %Corta cuando ya recorrio todas las filas
encontrar_butaca2(Cant,F,C,Bandera,Lista):-encontrar_butaca_no_pasillo(Cant,0,1,1,Lista), F2 is F+1 ,encontrar_butaca2(Cant,F2,C,Bandera,Lista). %va recorriendo todas las columnas llamando a encontrar_butaca_no_pasillo y las filas llamandose recursivamente

encontrar_butaca1(_,9,_,_,_). %Corta cuando ya recorrio todas las filas
encontrar_butaca1(Cant,F,C,Bandera,Lista):-encontrar_butaca_pasillo(Cant,0,1,1,Lista), F2 is F+1 ,encontrar_butaca1(Cant,F2,C,Bandera,Lista). %va recorriendo todas las columnas llamando a encontrar_butaca_no_pasillo y las filas llamandose recursivamente

suma([],0):-!.
suma([X|Resto],Resul):-suma(Resto,Resul2), gasto(X,_,_), con_descuento(X,Suma), Resul is Resul2 + Suma,!.
suma([_|Resto],Resul):-suma(Resto,Resul).

precio_aux([_,F,_,_],800):-precio1(X),miembro(F,X),!.
precio_aux([_,F,_,_],950):-precio2(X),miembro(F,X).
%precio_aux([_,F,_,_],Resul).

precio([],0):-!.
precio([X|Resto],Resul):-precio(Resto,Resul2),precio_aux(X,Total), Resul is Total + Resul2,!. 
precio([_|Resto],_):-precio(Resto,_).
%precio([ [_,1,_,_] , [_,2,_,_] , [_,3,_,_] ], Resul).

encontrar_butaca(Cant,Cond,Lista):-Cond == 'no_pasillo',encontrar_butaca2(Cant,Cond,Lista).
encontrar_butaca(Cant,Cond,Lista):-Cond == 'pasillo',encontrar_butaca1(Cant,Cond,Lista).

cinemark(Cant,Cond,[Lista|Total]):-encontrar_butaca(Cant,Cond,Lista),precio(Lista,Total).

