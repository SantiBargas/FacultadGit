%para sacar todos los gastos
%recorrer lista de todos los participantes de la peña

gasto(pablo,4500).
gasto(gabriel,1450).
gasto(federico,850).
gasto(franco,800).
billetera(pablo).
billetera(federico).

concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):- concatenar(L1,L2,L3).

%Funcion auxiliar que se fija si uso la billetera para aplicarle el descuento al gasto.
gasto_total(X,V,V1):-not(billetera(X)),V1 is V,!.
gasto_total(X,V,V1):-billetera(X), V1 is 0.7 * V.
%gasto_total(pablo,4500,V). V= 3.150
%gasto_total(gabriel,4500,V). V= 1450


%Funcion que calcula el total del gasto de la peña aplicando el descuento de la billetera (añadir el gasto_total).
total([],0):-!.
total([X|Resto],T):-total(Resto,T2), gasto(X,V),gasto_total(X,V,V1), T is T2 + V1,!. 
total([_|Resto],T):-total(Resto,T).
% total([juan, agustin, franco, pablo, gabriel, ulises, federico] , V). V=5995.0


%Funcion que cuenta la cantidad de los que compran
cantidad([],0):-!.
cantidad([_|Resto],Elementos):- cantidad(Resto,Elementos2), Elementos is Elementos2 + 1,!.
cantidad([_|Resto],Elementos):-cantidad(Resto,Elementos).
%cantidad([juan, agustin, franco, pablo, gabriel, ulises, federico],N). N=7

%Funcion que calcula lo que tienen que pagar los que no pusieron nada
total_t(V,N,R):- R is V / N.
%total_t(5995,7,R). R=856


%Funcion que calcula si tiene que recibir o pagar
recibe_paga_aux(X,R,N):-not(gasto(X,_)),concatenar([X],["paga"],C2),concatenar(C2,R,N),!.
recibe_paga_aux(X,R,N):-gasto(X,V),gasto_total(X,V,V1), V2 is V1 - R , V2 > 0 , concatenar([X],["recibe"],C2),concatenar(C2,V2,N),!.
recibe_paga_aux(X,R,N):-gasto(X,V),gasto_total(X,V,V1), V2 is V1 - R , V2 < 0 , V3 is V2 * -1, concatenar([X],["recibe"],C2),concatenar(C2,V3,N),!.
%recibe_paga_aux(juan,856,N). "juan paga 851"
%recibe_paga_aux(franco,856). "franco paga 50"
%recibe_paga_aux(pablo,856). "pablo recibe 2298"

%Funcion que llama recursivamente a recibe_paga_aux con cada nombre de la lista
recibe_paga2([],[]).
recibe_paga2([X|Resto],[Resul|Resto2]):-recibe_paga_aux(X,856,Resul),recibe_paga2(Resto,Resto2).
%recibe_paga([X|Resto],[Resul|Resto]):-cantidad([X|Resto],Cantidad),total([X|Resto],Total),total_t(Total,Cantidad,Totalidad),recibe_paga2([X|Resto],[Resul|Resto2],Totalidad).

%recibe_paga([X|Resto],R):-recibe_paga(Resto,R),recibe_paga_aux(X,856). ahi me tira los resultados pero calculando la totalidad no
%recibe_paga([juan, agustin, franco, pablo, gabriel, ulises, federico],N).


similitud([],_,0,[]).
similitud([P|R1],LsContiene,Cantidad,Resul):-miembro(P,LsContiene),similitud(R1,LsContiene,Aux,Resul),Cantidad is Aux +1,!.
similitud([P|R1],LsContiene,Cantidad,[P|Resul]):- similitud(R1,LsContiene,Cantidad,Resul).

