Algoritmo Parcial_Ejercicio1
	
	Dimension V[6,30]
	
	Para codComision<-1 hasta 6 Hacer
		Para codAlumno <-1  Hasta 30 Hacer
			V[codcomision,codalumno]<-0 
		FinPara
	FinPara
	
	Escribir "ingrese la comision del alumno de 1 a 6 en 0 termnina"
	Leer codComision
	
	Mientras codComision<>0 Hacer
		Escribir "ingrese el codigo de alumno de 1 a 30"
		Leer codAlumno
		Escribir "ingrese la nota del alumno"
		Leer nota
		
		V[codcomision,codalumno]<- Nota+V[Codcomision,codalumno]
		
		Escribir "ingrese la comision del alumno de 1 a 6 en 0 termnina"
		Leer codcomision
		
	FinMientras
	
	///IncisoA
	
	Para Codcomision<-1 hasta 6 Hacer
		
		TotalNotas<-0
		Alumnos<-0
		
		Para codalumno<-1 hasta 30 hacer
			
			Si V[codcomision,codalumno] <> 0 Entonces
				TotalNotas<- TotalNotas+ V[codcomision,codalumno]
				Alumnos<-Alumnos+1
			FinSi
			
		FinPara
		PromComision<-TotalNotas/Alumnos
		Escribir "El promedio de la comision " ,codcomision, "es de " ,PromComision
		
	FinPara
	
	///Inciso B
	
	Para codcomision<-1 Hasta 6 Hacer
		
		CantAprobados<-0
		Para codalumno<-1 Hasta 30 Hacer
			
			Si V[codcomision,codalumno] >=60 entonces
				CantAprobados<-CantAprobados+1
			FinSi
			
		FinPara
		Escribir "la cantidad de aprobados de la comision " ,codcomision, "son " ,cantaprobados
		
	FinPara
	
	///Inciso C
	
	Para codcomision<-1 Hasta 6 Hacer
		asistencia<-0
		Para codalumno<-1 Hasta 30 Hacer
			
			Si V[codcomision,codalumno] <> 0 Entonces
				
				asistencia<-asistencia +1
				
			FinSi
			
		FinPara
		porcentasis<-(asistencia*100)/30
		Escribir "el porcentaje de asistencia de la comision " ,codcomision, " es de " ,porcentasis, "porciento (%)"
		
	FinPara
	
	
FinAlgoritmo
