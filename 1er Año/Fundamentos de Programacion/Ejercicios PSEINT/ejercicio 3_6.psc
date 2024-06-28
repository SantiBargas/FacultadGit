Algoritmo ejercicio3_6
	estudiante <- 0
	femenino <- 0
	masculino <- 0
	Mientras estudiante<3 Hacer
		Escribir 'ingresar sexo ( 1= varon , 2=mujer )"
		Leer sexo
		Si sexo<- 2 Entonces
			Escribir 'ingresar altura del estudiante mujer'
			Leer AlturaMujer
			Si AlturaMujer>1.75 Entonces
				femenino <- femenino + 1
			FinSi
		SiNo
			Escribir 'ingresar altura del estudiante varon'
			Leer AlturaVaron
			Si AlturaVaron>1.95 Entonces
				masculino <- masculino + 1
			FinSi
		FinSi
		estudiante <- estudiante+1
	FinMientras
	Escribir 'la cantidad de estudiantes femeninas mayores a 1,75 de altura son:,' ,femenino
	Escribir 'la cantidad de estudiantes masculinos mayores a 1,95 de altura son:,' ,masculino
FinAlgoritmo
