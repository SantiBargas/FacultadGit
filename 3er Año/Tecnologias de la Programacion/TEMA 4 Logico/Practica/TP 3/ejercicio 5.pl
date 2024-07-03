%5. Dadas dos palabras, representadas como listas de caracteres, evaluar la semejanza entre las mismas.
%Para esto se verificarán, por posición, las letras de las dos palabras, cada coincidencia sumará un punto
%y cada vez que las letras no coincidan se restará un punto.
%Ejemplos:
%semejanza([h,o,l,a], [h,o,l,o], S). --> S = 2.
%semejanza([m,e,s,a], [m,e,s,a,d,a], S). --> S = 2.
%semejanza([s,o,l,a], [m,o,n,a], S). --> S = 0.
%semejanza([s,o,l], [c,a,s,a], S). --> S = -4.


semejanza([],[],0):-!.
semejanza([_|Resto],[],S):- semejanza(Resto,[],Aux), S is Aux-1.
semejanza([],[_|Resto],S):- semejanza([],Resto,Aux), S is Aux-1.
semejanza([_|Resto1],[_|Resto2],S):-semejanza(Resto1,Resto2,Aux),S is Aux+1.
semejanza([_|Resto1],[_|Resto2],S):-semejanza(Resto1,Resto2,Aux),S is Aux-1.
