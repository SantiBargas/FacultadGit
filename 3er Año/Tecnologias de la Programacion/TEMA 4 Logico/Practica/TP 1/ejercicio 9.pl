%9. Construir un programa Prolog que pueda responder consultas acerca de los gustos literarios de
%distintos grupos de personas, a partir de la siguiente información:
%A los abogados les gustan las novelas largas.
%Tanto a los ingenieros como a los médicos les gustan las novelas.
%A las mujeres les gustan todos los libros largos.
%A los contadores varones les gustan tanto los libros de cuentos como los libros de poemas.
%Haydée es una mujer que es abogada y también ingeniera.
%Tania es una mujer médica.
%Livio es un varón contador a quien le gusta "Rayuela".
%Pedro es un abogado varón a quien le gustan los libros de cuentos.
%"Rayuela" y "Karamazov" son novelas largas.
%"Octaedro" es un libro de cuentos corto.
%"Inventario" es un libro de poemas largo.
%"Leones" es una novela corta.
%Formular las siguientes consultas:
%a. ¿Qué libros le gustan a Livio? (respuestas "Octaedro", "Inventario" y "Rayuela")
%b. ¿A quiénes les gusta "Leones"? (respuestas "Haydée" y "Tania")
%c. ¿Qué libros cortos tiene registrado el programa? (respuestas "Octaedro" y "Leones")
%Indicar cómo se haría cada una de estas tres consultas.
%Agregar al programa la posibilidad de responder consultas acerca de qué libros son
%valiosos. Se considera que un libro es valioso si le gusta a, al menos, dos personas
%distintas.

novelaslargas(abogados).

novelas(ingenieros).
novelas(medicos).

libroslargos(mujeres)

cuentos(contadorvaron).
poemas(contadorvaron).

mujer(haydee).
abogada(haydee)
ingeniera(haydee)

mujer(tania).
medica(tania).

varon(livio).
contador(livio).
rayuela(livio).

varon(pedro).
abogado(pedro).
cuentos(pedro).

novelaslargas(rayuela).
novelaslargas(karamazov).
cuentoscorto(octaedro).
poemaslargo(inventario).
novelacorta(leones).