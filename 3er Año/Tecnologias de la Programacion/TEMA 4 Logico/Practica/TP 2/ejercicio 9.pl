%9. Escriba un programa en Prolog que dada una lista numérica ordenada, inserte un elemento en
%el lugar correspondiente según el orden.
%Ej.: insertar(3, [1, 2, 4, 5], Resultado). => Resultado = [1, 2, 3, 4, 5].

insertar(X,[],[X]). %condicion de corte: llegue al final y es mayor que todos.
insertar(N,[X|R],[N|[X|R]]):- X > N. % cuando X es mayor que N, lo agrego antes de todo el [X|R]
insertar(N,[X|R1],[X|R2]):- insertar(N,R1,R2). %cuando X es menor que N.