%3. Implementar un predicado “eliminar_primero/3” que quite de una lista la primera aparición de un
%determinado elemento, utilizar el operador de corte donde considere necesario para garantizar que no
%se realicen unificaciones innecesarias.
%Ejemplo:
%eliminar_primero([1, 2, 3, 1, 2, 3], 2, X).
%X = [1, 3, 1, 2, 3].
%eliminar_primero([1, 2, 3, 1, 2, 3], a, X).
%X = [1, 2, 3, 1, 2, 3].

eliminar_primero([],_,[]).
eliminar_primero([E|Resto],E,Resto):-!.
eliminar_primero([X|Resto],E,[X|Lista]):-eliminar_primero(Resto,E,Lista).
