%2. Dado el siguiente programa en Prolog:
p(1).
p(2):-!.
p(3).
%Evaluar las siguientes consultas, dejando registrado para cada una el resultado obtenido, y en lenguaje
%natural, por que se obtiene dicho resultado detallando los puntos de elección que han sido desechados
%y cual es el operador de corte por el cual han sido quitados.
%a. p(X).
%b. p(X), p(Y).
%c. p(X), !, p(Y).

%a X=1 X=2 y corta

%b X=Y Y=1; X=1 Y=2; X=2 Y=1 

%c X=1 Y=1 Y=2 