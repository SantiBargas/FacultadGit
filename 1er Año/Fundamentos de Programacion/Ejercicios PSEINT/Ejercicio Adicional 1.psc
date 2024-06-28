Algoritmo sin_titulo
	Dimension M[10,10]
	Dimension Vector[45]
	
	
	
	Para f<-1 hasta 10 Hacer
		Para c<-1  Hasta 10 Hacer
			M[f,c]<- 10 + azar(85)
			Escribir M[f,c], " " Sin Saltar
		FinPara
		Escribir ""
		Escribir ""
	FinPara
	
	
	Cont<- 0
	Para f<-1 Hasta 9 Hacer
		
		Para c <-f+1 Hasta 10 Hacer
			Cont<- cont +1
			Vector[Cont]<- M[f,c]
			
			Escribir Vector[Cont]
			
		FinPara
	FinPara
	
	
	
FinAlgoritmo
