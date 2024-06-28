Algoritmo sin_titulo
	Leer Equipo1
	Leer Equipo2
	
	GanadorEq1<-0
	GolesEq1<-0
	
	
	GanadorEq2<-0
	GolesEq2<-0
	
	Escribir "IngreseCantidad de partidos"
	Leer N
	
	Para i<-1 Hasta N Hacer
		Escribir "ingrese goles de" ,Equipo1
		Leer Goles1
		GolesEq1<- Goles1 + GolesEq1
		
		Escribir "Ingrese goles de" ,Equipo2
		Leer Goles2
		GolesEq2<- Goles2	+ GolesEq2
		
		Si Goles1 > Goles2 Entonces
			GanadorEq1<- GanadorEq1+1
		SiNo
			GanadorEq2<- GanadorEq2+1
		FinSi
	FinPara
	
	Si GanadorEq1> GanadorEq2 Entonces
		
		Escribir "El equipo que mas partidos gano y mas goles anoto es",Equipo1
	SiNo	
		Escribir "El equipo que mas partidos gan es",Equipo2 
	FinSi
	
	Si GolesEq1 > GolesEq2 Entonces
		
		Escribir "el que mas goles anoto es ", Equipo1, "Con un total de" ,GolesEq1
	SiNo
		Escribir "el que mas goles anoto es ", Equipo2, "Con un total de" ,GolesEq2
	FinSi
	
FinAlgoritmo
