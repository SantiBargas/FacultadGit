gasto(pablo,4500,true).
gasto(gabriel,1450,fail).
gasto(federico,800,true).
gasto(franco,800,fail).

concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).

cantidad([],0):-!.
cantidad([X|Resto],Elementos):- cantidad(Resto,Elementos2), Elementos is Elementos2 + 1,!.
cantidad([X|Resto],Elementos):-cantidad(Resto,Elementos).
%cantidad([juan, agustin, franco, pablo, gabriel, ulises, federico],N).

suma_t([],0):-!.
suma_t([X|Resto],Cantidad):-suma_t(Resto,Cantidad2),total(X,T), Cantidad is Cantidad2 + T,!.
suma_t([X|Resto],Cantidad):-suma_t(Resto,T).
%suma_t([juan, agustin, franco, pablo, gabriel, ulises, federico],T). T=5960.

total(X,0):-not(gasto(X,S,C)),!.
total(X,T):-gasto(X,S,C),C==fail,T is S,!.
total(X,T):-gasto(X,S,C),C==true,T is S * 0.7 . 
%total(pablo,T). T=3150
%total(gabriel,T). T=1450
%total(ulises,T). T=0

totalidad(X,Y,T):-T is X/Y.
%totalidad(5960,7,T).

recibe_paga(Nombre,Gasto,[Nombre,"paga",Gasto]):- not(gasto(Nombre,T,C)),!.
recibe_paga(Nombre,Gasto,[Nombre,"recibe",Cant]):- total(Nombre,T),Cant is T-Gasto, Cant > 0,!.
recibe_paga(Nombre,Gasto,[Nombre,"paga",Cant2]):- total(Nombre,T),Cant is T-Gasto, Cant < 0 ,Cant2 is Cant * -1.
%recibe_paga(juan,856,R). R=[juan paga 856].
%recibe_paga(pablo,856,R). R=[pablo recibe 2298].
%recibe_paga(franco,856,R). R=[franco paga 56].


peña_aux([],[],Total):-!.
peña_aux([X|Resto],[R|Resul],Total):-recibe_paga(X,Total,R),peña_aux(Resto,Resul,Total).

peña([X|Resto],R):-cantidad([X|Resto],Cantidad),suma_t([X|Resto],Suma),totalidad(Suma,Cantidad,Total),peña_aux([X|Resto],R,Total).

%peña([juan, agustin, franco, pablo, gabriel, ulises, federico], Resultado).
