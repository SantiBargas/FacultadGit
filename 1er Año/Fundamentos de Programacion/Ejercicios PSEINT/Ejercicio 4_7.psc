Algoritmo sin_titulo
	
	Dimension N[6,4]
	
	Para Fila<-1 hasta 6 Hacer
		Para Colum<-1 Hasta 4 Hacer
			N[Fila,Colum] <- azar(80) +10
			Escribir N[Fila,Colum], " "  Sin Saltar
		FinPara
		Escribir ""
		Escribir ""
	FinPara
	
	Escribir "el elemento en la fila 2 elemento 4 es" ,N[2,4]
	
	Escribir "Elementos 3er columna"
	Para Fila<-1 Hasta 6 Hacer
		Escribir N[Fila,3]
	FinPara
	
	Escribir "Elementos fila 5"
		Para Colum<-1 Hasta 4 Hacer
		Escribir N[5,Colum], " " Sin Saltar
	FinPara
	
FinAlgoritmo


