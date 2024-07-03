progenitor(maria,manuel).
progenitor(pedro,manuel).
progenitor(maria,miguel).
progenitor(pedro,miguel).

hombre(manuel).
hombre(pedro).
hombre(miguel).
mujer(maria).

%A
padre(P,H):-progenitor(P,H),hombre(P).

%B
madre(M,H):-progenitor(M,H),madre(M).

%C
abuelo(A,H):-hombre(A),progenitor(A,P),progenitor(P,H).
%abuelo(A,H):-padre(A,P),progenitor(P,H).

%D
abuela(A,H):-madre(A,P),progenitor(P,H).

%E
hermane(A,B):-progenitor(C,A),progenitor(C,B),hombre(A),A\=B.
hermane(A,B):-padre(Pa,A),padre(Pa,B),madre(Ma,A),madre(Ma,B),A\=B.

%F
hermano(A,B):-hombre(A),padre(Pa,A),padre(Pa,B),madre(Ma,A),madre(Ma,B),A\=B.

%G
hermana(A,B):-mujer(A),padre(Pa,A),padre(Pa,B),madre(Ma,A),madre(Ma,B),A\=B.

%H
sucesor(A,B):-progenitor(B,A);abuelo(B,A);abuela(B,A);
sucesor(S,P):-progenitor(P,S);progenitor(X,S);sucesor(X,P).


progenitor(X,Y):-madre(X,Y).
progenitor(X,Y):-padre(X,Y).
