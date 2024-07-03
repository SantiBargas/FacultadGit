%8 Cree un programa que encuentre la salida dado el plano de una casa, para lo cual:
%a. Debe resolver cómo modelar el plano.
%b. Debe encontrar la forma de avanzar en el camino hacia la salida.
%c. Debe verificar que no se formen bucles en el camino.
%Ejemplo:
%salir(a, Camino).
%Camino = [a, b, c, g, Salida];
%Camino = [a, b, e, f, g, Salida];
%Camino = [a, d, f, g, Salida];
%Camino = [a, d, f, e, b, c, g, Salida].
agregar_nuevo(E,[],[E]):-!.
agregar_nuevo(E,[E|R],[E|R]):-!.
agregar_nuevo(E,[X|R],[X|Lista]):- agregar_nuevo(E,R,Lista).

miembro(X,[X|_]).
miembro(X,[_|R]):-miembro(X,R).

conectado(a,b).
conectado(a,d).
conectado(b,c).
conectado(b,e).
conectado(c,g).
conectado(d,f).
conectado(e,b).
conectado(e,f).
conectado(f,e).
conectado(f,g).
conectado(g,salida).

conectados(X,Y):-conectado(Y,X).
conectados(X,Y):-conectado(X,Y).

salir_aux(salida,Camino,Camino).
salir_aux(Hab,Camino,Solucion):-conectados(Hab,X),not(miembro(X,Camino)),agregar_nuevo(X,Camino,Recorrido),salir_aux(X,Recorrido,Solucion).

salir2(Hab,Camino):-salir_aux(Hab,[Hab],Camino).

