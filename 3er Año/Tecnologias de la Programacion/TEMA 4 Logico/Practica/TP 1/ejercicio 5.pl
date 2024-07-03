%5. Dada la siguiente rutas de colectivo
%Realice las consultas en prolog para obtener las siguientes respuestas
%A ¿Desde que orígenes se llega a Córdoba?
%B ¿Qué destinos son alcanzados desde Paraná?
%C ¿Hay alguna ruta entre Paraná y Córdoba?
%D ¿Hay alguna combinación de dos rutas que permita ir desde Santa Fe a Corrientes?
 ruta(santafe, parana).
 ruta(parana, corrientes).
 ruta(santafe, cordoba).
 ruta(santafe, coronda).
 ruta(santafe, rosario).
 ruta(rosario, capital).
 ruta(rosario, mardelplata).
 ruta(capital, cordoba).

camino(A,B):-ruta(A,Z),ruta(Z,B).

%A ruta(X,'cordoba').
%B ruta('parana',Y).
%C ruta('parana','cordoba').
%D camino('santafe','corrientes').
