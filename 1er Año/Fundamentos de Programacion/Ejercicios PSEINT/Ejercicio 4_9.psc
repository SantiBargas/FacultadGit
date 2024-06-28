Algoritmo sin_titulo
	Dimension Venta[10,4]
	
	Para fila<-1 hasta 10 hacer
		Para colum<-1 Hasta 4 hacer
			Venta[fila,colum]<- azar(9)
		FinPara
	FinPara
	Para fila<-1 hasta 10 hacer
		Para colum<-1 Hasta 4 hacer
			Escribir Venta[fila,colum]," " Sin Saltar
		FinPara
		Escribir ""
	FinPara
	
	
	///Inciso a
	Para fila<-1 Hasta 10 Hacer
		SumaTotal<-0
		Para colum<- 1 Hasta 4 Hacer
			SumaTotal <- SumaTotal + Venta[fila,colum] 
		FinPara
		Escribir "las cantidades vendidas del articulo",fila, "es" ,SumaTotal
	FinPara
	
	
	///inciso b
	Sum3<-0
	Para fila<-1 Hasta 10 Hacer
		Sum3<- Sum3 + Venta[fila,3]
	FinPara
	Escribir "el total de unidades vendidas de la colum 3 es" ,Sum3
	
	
	///IncisoC
	Escribir "La cant vendida del articulo 6 por la sucursal 1 es:" ,Venta[6,1]
FinAlgoritmo
