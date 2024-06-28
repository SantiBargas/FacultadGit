Algoritmo sin_titulo
	Dimension E[6,5]
	///declaro la matriz en 0
	Para Equipo<-1 Hasta 6
		Para Tipo<-1 Hasta 5 Hacer
			E[Equipo,Tipo]= 0
		FinPara
	FinPara
	
	Escribir "Ingrese Nro de equipo (0 termina)"
	
	Leer Equipo
	Mientras Equipo <> 0 Hacer
		Escribir "Ingrese tipo de Emergencia (1 a 5)"
		Leer Tipo
		Escribir "Ingrese el dia"
		Leer dia
		
		E[Equipo,Tipo] = E[Equipo,Tipo] +1 
		
		Escribir "Ingrese nro de equipo ( 0 termina)"
		Leer Equipo
	FinMientras
	
	
FinAlgoritmo
