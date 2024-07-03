hijo(tomas,juan).
hijo(ana,tomas).
hijo(juan,marcos).
hijo(alicia,juan).

nieto(X,Y):- hijo(X,Z), hijo(Z,Y).