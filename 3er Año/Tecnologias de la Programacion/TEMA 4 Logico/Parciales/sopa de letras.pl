

s([ [q,h,o,l,a],[u,o,r,w,q],[k,l,q,a,z],[z,a,y,w,e],[z,x,c,v,b]]).

%S= [   [q,h,o,l,a],
%	[u,o,r,w,q],
%	[k,l,q,a,z],
%	[z,a,y,w,e],
%	[z,x,c,v,b] ]	

%BUSCAR PALABRA EN FILA/RENGLON
%Bandera = 0 todavia no encontre coincidencia parcial, 1 encontre parcial.
encontrar_palabra([],_,_,_):-!.
encontrar_palabra([C1|R1],[C2|R2],0,Palabra):- C1\=C2,encontrar_palabra([C1|R1],R2,0,Palabra),!.
encontrar_palabra([C1|R1],[C1|R2],0,Palabra):- encontrar_palabra(R1,R2,1,Palabra),!. %activamos la bandera pq empezamos a buscar la palabra y asegurarnos q es consecutiva la busqueda
encontrar_palabra([C1|R1],[C1|R2],1,Palabra):- encontrar_palabra(R1,R2,1,Palabra),!.
encontrar_palabra([C1|_],[C2|R2],1,Palabra):- C1\=C2,encontrar_palabra(Palabra,[C2|R2],0,Palabra).
%encontrar_palabra([h,o,l,a],[q,h,h,o,l,a,1],0,[h,o,l,a]).

pasar_primero([],[],[]):-!.
pasar_primero([[X|R]|RF1],[X|RC],[R|RF2]):-pasar_primero(RF1,RC,RF2).
%caso 1: las filas estan vacias
inversa([[]|_],[]):-!.
%caso 2: pasamos el primero de cada fila a C, y hacemos la llamada recursiva con S sin los primero de cada fila
inversa(S,[C|RC]):-pasar_primero(S,C,SSinPrimero),inversa(SSinPrimero,RC).
%inversa([ [q,h,o,l,a],[u,o,r,w,q],[k,l,q,a,z],[z,a,y,w,e],[z,x,c,v,b]],C).

%Recibe la sopa de letras y busca la palabra en cada columna recursivamente
busqueda_columnas(_,[],_):-!,fail.
busqueda_columnas(P,[C|_],N1):-encontrar_palabra(P,C,0,P),write('true. Se encuentra en la columna '),write(N1),write('.\n').
busqueda_columnas(P,[_|R],N1):-N2 is N1+1,busqueda_columnas(P,R,N2).
%busqueda_columnas([h,o,l,a],[[q,u,k,z,z],[h,o,l,a,x],[o,r,q,y,c]],1).

busqueda_filas(_,[],_):-!,fail.
busqueda_filas(P,[C|_],N1):-encontrar_palabra(P,C,0,P),write('true. Se encuentra en la fila '),write(N1),write('.\n').
busqueda_filas(P,[_|R],N1):-N2 is N1+1,busqueda_filas(P,R,N2).
%busqueda_filas([h,o,l,a],[[q,h,o,l,a],[u,o,r,w,q],[k,l,q,a,z],[z,a,y,w,e],[z,x,c,v,b]],1).

sopa(P,S):-busqueda_filas(P,S,1),inversa(S,S2),busqueda_columnas(P,S2,1),write('fail. no hay otra aparcion de la palabra'),!.

%sopa(S,[h,o,l,a],L).
%sopa([h,o,l,a], [[q,h,o,l,a],[u,o,r,w,q],[k,l,q,a,z],[z,a,y,w,e],[z,x,c,v,b]]).
