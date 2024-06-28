Algoritmo sin_titulo
	Dimension Dist[6,20] /// 6 camiones, 20 productoss
	Dimension Faltantes[20]///Faltantes de mercaderia
	
	Para Camion<-1 Hasta 6 Hacer
		Para Art<-1 Hasta 20 Hacer
			Dist[Camion,Art]<- azar(50)
		FinPara
	FinPara
	
	Para Art<-1 Hasta 20 Hacer
		Faltantes[Art]<- 0
	FinPara
	
	Leer Camion
	
	Mientras Camion<>0 Hacer
		Escribir "ingrese cod de articulo de 1 a 20"
		Leer Art
		Escribir "Ingrese cantidad vendidad"
		Leer Cantidad
		
		Si Dist[Camion,Art]>= Cantidad Entonces
			
			CantVendida<- Cantidad
		SiNo
			
			///Significa que no hay stock suficiente
			CantVendida<- Dist[Camion,Art] ///Entrego el stock que me queda
			Faltan<- Cantidad - Dist[Camion,Art]
			Faltantes[Art]<- Faltantes[Art] + Faltan ///Acumulo el faltante del articulo
		FinSi
		
		///Una vez que determino la cantidad que puedo vender, lo resto del stock
		Dist[Camion,Art] <- Dist[Camion,Art] - CantVendida
		
		Escribir "Ingrese Cod Camion 1 a 6 "
		Leer Camion
	FinMientras
	
	
	///Inciso A
	Para Art<-1 Hasta 20 Hacer
		
		FinalProduc<-0
		Para Camion<- 1 Hasta 6 Hacer
			FinalProduc<-Dist[Camion,Art]+FinalProduc
		FinPara
		Escribir "Del articulo ",art, "quedaron" ,FinalProduc 
	FinPara
	
	///Incisio B
	
	Leer ArtBuscar
	
	MayorStock<-0
	
	Para camion<-1 Hasta 6 hacer
		Si Dist[Camion,Art] > MayorStock Entonces
			MayorStock<- Dist[Camion,Art]
			MayorCamion<- Camion
		FinSi
	FinPara
	
	Escribir "El camion", MayorCamion, " Es el que mas tiene del articulo" ,ArtBuscar
	
	///Informar Faltantes
	Para art<-1 Hasta 20 Hacer
		
		Si Faltantes[Art] > 0 Entonces
			Escribir "Cod",Art,"Faltaron ",Faltantes[Art]
		FinSi
		
	FinPara
FinAlgoritmo
