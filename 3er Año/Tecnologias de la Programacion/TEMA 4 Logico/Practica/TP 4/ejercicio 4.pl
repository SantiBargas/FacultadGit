viaje('Paran�', 'Santa Fe', 7, 1).
viaje('Paran�', 'Santa Fe', 13, 1).
viaje('Paran�', 'Santa Fe', 18, 1).
viaje('Santa Fe', 'Paran�', 4, 1).
viaje('Santa Fe', 'Paran�', 13, 1).
viaje('Santa Fe', 'Paran�', 19, 1).
viaje('Paran�', 'Corrientes', 3, 9).
viaje('Paran�', 'Corrientes', 8, 9).
viaje('Paran�', 'Corrientes', 16, 9).
viaje('Corrientes', 'Paran�', 0, 9).
viaje('Corrientes', 'Paran�', 10, 9).
viaje('Corrientes', 'Paran�', 18, 9).
viaje('Santa Fe', 'Rosario', 5, 3).
viaje('Santa Fe', 'Rosario', 9, 3).
viaje('Santa Fe', 'Rosario', 20, 3).
viaje('Rosario', 'Santa Fe', 3, 3).
viaje('Rosario', 'Santa Fe', 11, 3).
viaje('Rosario', 'Santa Fe', 18, 3).
viaje('Santa Fe', 'C�rdoba', 6, 5).
viaje('Santa Fe', 'C�rdoba', 16, 5).
viaje('Santa Fe', 'C�rdoba', 22, 5).
viaje('C�rdoba', 'Santa Fe', 8, 5).
viaje('C�rdoba', 'Santa Fe', 14, 5).
viaje('C�rdoba', 'Santa Fe', 20, 5).
viaje('Santa Fe', 'Resistencia', 3, 9).
viaje('Santa Fe', 'Resistencia', 12, 9).
viaje('Santa Fe', 'Resistencia', 19, 9).
viaje('Resistencia', 'Santa Fe', 6, 9).
viaje('Resistencia', 'Santa Fe', 12, 9).
viaje('Resistencia', 'Santa Fe', 16, 9).
viaje('Corrientes', 'Resistencia', 8, 1).
viaje('Corrientes', 'Resistencia', 12, 1).
viaje('Corrientes', 'Resistencia', 16, 1).
viaje('Resistencia', 'Corrientes', 9, 1).
viaje('Resistencia', 'Corrientes', 11, 1).
viaje('Resistencia', 'Corrientes', 17, 1).
viaje('Resistencia', 'Tucum�n', 2, 5).
viaje('Resistencia', 'Tucum�n', 8, 5).
viaje('Resistencia', 'Tucum�n', 19, 5).
viaje('Tucum�n', 'Resistencia', 4, 5).
viaje('Tucum�n', 'Resistencia', 7, 5).
viaje('Tucum�n', 'Resistencia', 12, 5).
viaje('Tucum�n', 'Resistencia', 18, 5).
viaje('C�rdoba', 'Tucum�n', 5, 8).
viaje('C�rdoba', 'Tucum�n', 11, 8).
viaje('C�rdoba', 'Tucum�n', 22, 8).
viaje('Tucum�n', 'C�rdoba', 7, 8).
viaje('Tucum�n', 'C�rdoba', 12, 8).
viaje('Tucum�n', 'C�rdoba', 18, 8).


%H=  horario salida + horario del viaje + horario de espera

%evaluamos el valor H con el valor de salida del proximo viaje que sea >=2 para la espera


suma_horas(Horas,Cantidad,Resul):-Aux is Horas+Cantidad, Aux >=24, Resul is Aux - 24.
suma_horas(Horas,Cantidad,Resul):-Aux is Horas+Cantidad, Aux < 24, Resul is Aux.


camino_aux(Origen,Destino,Llegada,HorasAcum,_,[[Origen,Destino,Salida,Llego]]):-viaje(Origen,Destino,Salida,Horas),
										Cond is Salida - HorasAcum,
										Cond =< 2, Cond >= 0,
										suma_horas(HorasAcum,Cond,Espera),
										suma_horas(Espera,Horas,Llego),
										Llego =< Llegada.

camino_aux(Origen,Destino,Llegada,HorasAcum,_,[[Origen,Destino,Salida,Llego]]):-viaje(Origen,Destino,Salida,Horas),
										Posta \= Destino , 
										Cond is Salida-HorasAcum, 
										Cond =< 2,Cond>=0,	
										suma_horas(HorasAcum,Cond,Espera),
										not(miembro(Posta,Visitados)),
										suma_horas(Espera,Horas,Llego),
										camino_aux(Posta,Destino,Llegada,Llego,[Posta|Visitados],Resul).

%ciudades vecinas en el wrapper
camino(Origen,Destino,Llegada,[ [Origen,Posta,Salida,Llego]|Tramos]):-viaje(Origen,Destino,Salida,Horas),suma_horas(Salida,Horas,Llego),Llego =< Llegada.
camino(Origen,Destino,Llegada,[ [Origen,Posta,Salida,Llego]|Tramos]):- viaje(Origen,Destino,Salida,Horas),suma_horas(Salida,Horas,Llego),camino_aux(Posta,Destino,Llegada,Llego,[Posta|[Origen]],Tramos).
camino(Origen,Destino,Llegada,[ [Origen,Posta,Salida,Llego]|Tramos]):-viaje(Origen,Posta,Salida,Horas),suma_horas(Salida,Horas,Llego),camino_aux(Posta,Destino,Llegada,Llego,[Posta|[Origen]],Tramos).


%camino(Origen,Destino,HoraSalida,DuracionViaje).
%camino('Paran�', 'C�rdoba', 21, Tramos). Tramos = [['Paran�', 'Santa Fe', 13, 14], ['Santa Fe', 'C�rdoba', 16, 21]].