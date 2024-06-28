Algoritmo Ejercicio3
	
	Dimension V[7,12]
	
	Para i<-1 Hasta 7 Hacer ///matriz en 0 por si algun curso no realizo aportes
		Para j<-1 Hasta 12 Hacer
			V[i,j]<-0
		FinPara
	FinPara
	
	Escribir "ingrese curso de 1 a 7 (0 termina)"
	Leer Curso
	
	Mientras curso<>0 Hacer
		Escribir "ingrese mes"
		Leer Mes
		
		Escribir "ingrese monto que realizo el alumno"
		Leer Monto
		
		V[curso,mes]<- Monto+V[curso,mes]
		
		Escribir "ingrese curso de 1 a 7 (0 termina)"
		Leer curso
		
		
	FinMientras
	
	
	///Inciso A
	Para i<-1 Hasta 7 Hacer
		Escribir "el curso " ,i
		Para j<-1 Hasta 12 hacer
			Escribir "en el mes" ,j, "aporto" ,V[i,j]
			Escribir , " " Sin Saltar
			
		FinPara
		Escribir " "
		Escribir " "
	FinPara
	
	
	///Inciso B
	TotalJunio<-0
	Para curso<-1 Hasta 7 Hacer
		TotalJunio<- V[curso,6] + TotalJunio
	FinPara
	
	Escribir "en junio la escuela aporto un total de ",TotalJunio
	
	
	///Inciso C
	
	Escribir "el total aportado por 6to año en marzo es de " ,V[6,3]
	
	
FinAlgoritmo
