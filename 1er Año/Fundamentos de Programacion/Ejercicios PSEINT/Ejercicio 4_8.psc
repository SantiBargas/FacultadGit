Algoritmo sin_titulo
	Dimension A[8,12]
	Dimension B[8,12]
	Dimension Suma[8,12] 
	Dimension Prom[8,12] 
	
	Para fila<-1 hasta 8 Hacer
		Para colum<-1 Hasta 12 Hacer
			A[fila,colum]<- 10+ Azar(89)
			B[fila,colum]<- 10+ Azar(89)
		FinPara
	FinPara
	
	Para fila<-1 Hasta 8 Hacer
		Para colum<- 1 Hasta 12 hACER
			Suma[fila,colum]<- A[fila,colum]+B[fila,colum]
			Prom[fila,colum]<- (A[fila,colum]+B[fila,colum])/2
			
		FinPara
	FinPara
	
	Escribir "la matriz suma es"
	Para fila<-1 hasta 8 Hacer
		Para colum<-1 Hasta 12 Hacer
			Escribir Suma[fila,colum], " " Sin Saltar
		FinPara
		Escribir ""
		Escribir ""
	FinPara
	
	Escribir "la matriz prom es"
	Para fila<-1 hasta 8 Hacer
		Para colum<-1 Hasta 12 Hacer
			Escribir Prom[fila,colum], " " Sin Saltar
		FinPara
		Escribir ""
		Escribir ""
	FinPara
	
	
FinAlgoritmo
