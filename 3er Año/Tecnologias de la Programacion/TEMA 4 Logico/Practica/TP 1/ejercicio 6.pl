estrella(sol).
estrella(tierra).
orbita(sol,tierra).
orbita(tierra,luna).
orbita(tierra,luna2).

%a
planeta(P):-orbita(sol,P).  %P es un planeta si orbita al rededor de esa estrella
%planeta(P):-orbita(E,P),estrella(E),E==sol.
%planeta(P):-orbita(sol,P),estrella(sol).

luna(L):-orbita(P,L),planeta(P).
lunaDe(P,L):-orbita(P,L),planeta(P).


%b
cantidadLunas(P,cant):-
cantidadLunas(P,cant):-lunaDe(P,L)






%EN CONSOLA
%planeta(P)
%luna(L)

