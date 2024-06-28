Algoritmo sin_titulo
	Leer N
	Dimension V[N]		
	
	Para i<- 1 Hasta N Hacer
		Leer V[i]
		
	FinPara
	
	Pos<-1 ///Posicion donde esta garcia
	
	Mientras Pos<=N y V[Pos] <> "GARCIA" Hacer
		Pos<- Pos + 1
	FinMientras
	
	Si Pos<=10 Entonces
		Para i<- Pos+1 Hasta N Hacer ///Pos + 1 posicion siguiente a garcia
		V[i-1]<-V[i]
		FinPara
	Sino	
		Escribir "No hay garcia"
	FinSi	
	
	Para i<- 1 Hasta N-1 Hacer ///Escribir una menos pq eliminamos un elemento
		Escribir V[i]
	FinPara
	
	
FinAlgoritmo
