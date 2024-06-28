Algoritmo sin_titulo
	Dimension Venta[10,4]
	Dimension Precios[10]
	
	Para Suc <- 1 Hasta 4 Hacer
		Para Art <- 1 Hasta 10 Hacer
			//Siempre primero la fila que seria Art y despues la columna que seria suc
			Venta[Art,Suc] <- 10 + azar(80)
		FinPara
	FinPara
	
	///Generamos precios al azar
	Para Art<-1 Hasta 10 Hacer
		Precios[Art]<- 200 + Azar (800)
		Escribir " "
	FinPara
	
	///Mostrarla
	Para Art<-1 Hasta 10 Hacer
		Para Suc <-1 Hasta 4 Hacer
			Escribir Venta[Art,Suc], " " Sin Saltar
		FinPara
		Escribir " "
	FinPara
	
	///Total Recaudado por cada sucursal
	TotalEmpresa<-0
	RecaudacionMayor <- 0
	SucMayor<-0
	Para Suc<-1 Hasta 4 Hacer
		Recaudacion <- 0
		Para Art <-1 hasta 10 hacer
			Importe<- Venta[Art,Suc] + Precios[Art]
			Recaudacion<- Recaudacion + Importe
		FinPara
		Escribir "La recaudacion de la sucursal" ,Suc,  "Es de $" ,Recaudacion
		TotalEmpresa<- TotalEmpresa+Recaudacion
		
		Si Recaudacion > RecaudacionMayor Entonces
			RecaudacionMayor <- Recaudacion
			SucMayor <- Suc
		FinSi
		
	FinPara
	Escribir  "La empresa que tuvo la mayor recaudacion es ",SucMayor," y es de " ,RecaudacionMayor
	
	
	
	
	
FinAlgoritmo
