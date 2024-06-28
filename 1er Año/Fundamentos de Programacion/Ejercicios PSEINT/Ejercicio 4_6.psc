Algoritmo sin_titulo
	
	Leer Alum
	
	Dimension Aprobados[Alum], NoAprobados[Alum]
	///No se la cantidad q necesito en cada uno 
	///pero con la cantidad de alumnos ya me alcanza
	
	ContAP<-0
	ContNOAP<-0
	
	Para i<- 1 Hasta Alum Hacer
		
		Leer Nombre,Nota
		
		Si Nota>=7 Entonces
			Aprobados[ContAP+1]<- Nombre
			ContAP<- ContAP+1
		SiNo
			NoAprobados[ContNOAP+1] <- Nombre
			ContNOAP<- ContNOAP + 1
		FinSi
	FinPara
	
	Escribir "Aprobados"
	Para i<-1 Hasta ContAP Hacer
		Escribir Aprobados[i]
	FinPara
	
	Escribir "NoAprobados"
	Para i<-1 Hasta ContNOAP Hacer
		Escribir NoAprobados[i]
	FinPara
	
	
FinAlgoritmo
