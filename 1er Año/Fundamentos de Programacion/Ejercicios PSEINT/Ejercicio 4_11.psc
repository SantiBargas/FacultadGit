Algoritmo sin_titulo
	Dimension Emp[3,6]
	
	Para Tipo<-1 Hasta 3 Hacer
		Para Arq<-1 Hasta 6 Hacer
			Emp[Tipo,Arq]<-0
		FinPara
	FinPara
	
	Leer Arq
	
	Mientras Arq<> 0 Hacer
		Leer Tipo
		m2<-azar(200)
		Emp[Tipo,Arq]<- Emp[Tipo,Arq]+ m2
		Escribir "Ingrese el arquitecto y el tipo"
		Leer Arq
	FinMientras
	
	Para Tipo<-1 Hasta 3 Hacer
		Para Arq<-1 Hasta 6 Hacer
			Escribir Emp[Tipo,Arq], " " Sin Saltar
		FinPara
		Escribir " "
		Escribir " "
		Escribir " "
		
	FinPara
	
	///Inciso A
	Para Arq<-1 Hasta 6 Hacer
		Escribir "El arq " ,Arq, "construyo:"
		Para Tipo<-1 Hasta 3 Hacer
			
			Escribir " " ,Emp[Tipo,Arq], "m2 del tipo" ,Tipo
		FinPara
		
	FinPara
	
	///Inciso B
	
	TotalM2<-0
	
	Para Arq<-1 Hasta 6 Hacer
		
		Para Tipo<-1 Hasta 3 Hacer
			TotalM2<- TotalM2+ Emp[tipo,arq]
		FinPara
		
	FinPara
	Escribir "el total de m2 proyectado por la empresa es de: " ,TotalM2
	
	
FinAlgoritmo
