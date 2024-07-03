% Escriba como programa en ProLog el siguiente cuerpo de conocimientos:
%● leoncio es padre de alberto y de gerónimo.
%● alberto es padre de juan y de luis.
%● geronimo es padre de luisa.
%● A es hermano de B si A y B tienen un padre en común y son distintas personas.
%● A es nieto de B si el padre de A es hijo de B.
%Responder:
%a. ¿como consultaría si alberto es padre de luis?
%b. ¿como consultaría si luis es padre de alberto?
%c. ¿como consultaría quien es hermano de luis?
%d. ¿como consultaría de quien es nieto luisa?
%e. ¿como consultaría quien es nieto de quien?

padre (leoncio, alberto).
padre (leoncio, geronimo).

padre (alberto,juan).
padre(alberto,luis).
padre(geronimo, luisa).

hermano(A,B):-padre(Z,A),padre(Z,B),A\=B.
nieto(A,B):-padre(B,Z),hijo(Z,A).

%padre('alberto','luis').
%padre('luis','alberto').
%hermano('luis',Y).
%nieto(X,'luisa').
%nieto(X,Y).
