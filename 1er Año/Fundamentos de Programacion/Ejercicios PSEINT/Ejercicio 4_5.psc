Algoritmo sin_titulo
	Dimension V[11]
	
	N<- 10
	
	Para i<- 1 Hasta N Hacer
		Leer V[i]
	FinPara
	
	Escribir "ingrese posicion y apellido que desea ingresar"
	Leer Pos
	Leer Ape
	
	Para i<- N Hasta Pos Con Paso -1 Hacer 
		V[i+1]<- V[i ]
	FinPara
	
	V[Pos]<- Ape
	N<- N+1 ///La dimension debe valer 1 valor mas
	
	
	Para i<- 1 Hasta 11 Hacer
		Escribir V[i]
	FinPara
FinAlgoritmo
