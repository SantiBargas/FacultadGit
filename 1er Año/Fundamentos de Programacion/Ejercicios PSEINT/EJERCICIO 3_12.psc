Algoritmo ejercicio3_11
	Repetir
		Escribir "Ingrese la cantidad de estudiantes que aprobaron fisica, Si nadie aprobo C=0"
		Leer C
		Si C>0 Entonces
			Escribir "La cantidad de estudiantes que aprobaron", C
		SiNo
			Escribir "Nadie aprobo"
		FinSi
	Hasta Que C>0 O C=0
	
	EstudiantesMas9<-0
	Escribir "la cantidad de estudiantes que aprobaron fueron" ,C
	Repetir
		Escribir "Ingrese la nota del estudiante"
		Leer Nota
		Si Nota>=9 Entonces
			EstudiantesMas9 <- EstudiantesMas9 + 1
		FinSi
	Hasta Que Nota= 0
	
	PromedioDeEstudiantes<- C/EstudiantesMas9
Escribir "El promedio de estudiantes que aprobaron con mas de 9 son:" ,PromedioDeEstudiantes	
FinAlgoritmo

