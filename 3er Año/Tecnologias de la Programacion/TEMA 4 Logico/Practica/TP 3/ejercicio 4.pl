%4. Implementar un predicado “agregar_nuevo/3” que agregue a una lista un elemento, solo si la misma no
%lo contiene. Utilizar corte para no proceder en caso de detectar que el elemento ya existe.
%Ejemplo:
%agregar_nuevo(a, [1, 2, 3], X).
%X = [1, 2, 3, a].
%agregar_nuevo(1, [1, 2, 3], X).
%X = [1, 2, 3]


agregar_nuevo(E,[],[E]):-!.
agregar_nuevo(E,[E|R],[E|R]):-!.
agregar_nuevo(E,[X|R],[X|Lista]):- agregar_nuevo(E,R,Lista).



