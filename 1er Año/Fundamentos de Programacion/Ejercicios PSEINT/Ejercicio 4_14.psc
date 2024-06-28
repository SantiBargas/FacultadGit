Algoritmo Ejercicio4_14
	Dimension A[8,12] 
	Dimension B[8,12]
	Dimension SUMA[8,12]
	Dimension PRODUC[8,12]
	
	
	
	Para fila<-1 Hasta 8 Hacer
		
		Para colum<-1 hasta 12 Hacer
			A[fila,colum] <-  + azar(100)
			B[fila,colum] <- azar(100)
		FinPara
		
	FinPara
	
	Para fila<- 1 Hasta 8 Hacer
		
		Para colum<-1 Hasta 12 Hacer
			SUMA[fila,colum] <- A[fila,colum] + B[fila,colum]
			PRODUC[fila,colum] <- SUMA[fila,colum]/ 2
			
		FinPara
	FinPara
	
	Para fila<-1 Hasta 8 Hacer
		
		Para colum<- 1 Hasta 12 Hacer
			Escribir SUMA[fila,colum], " " sin saltar
		FinPara
		
		Escribir ""
		Escribir ""
	FinPara
	
	Para fila<-1 Hasta 8 Hacer
		
		Para colum<- 1 Hasta 12 Hacer
			Escribir PRODUC[fila,colum], " " sin saltar
		FinPara
		
		Escribir ""
		Escribir ""
	FinPara
	
	
	
	
	
	
	
	
	
FinAlgoritmo
