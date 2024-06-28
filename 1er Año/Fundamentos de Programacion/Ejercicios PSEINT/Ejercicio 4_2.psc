Algoritmo sin_titulo
	///Inciso A
	Dimension N[20]
	
	Para i=1 Hasta 20 Hacer
		Leer N[i]
	FinPara
	
	Notas<-0  ///Calcular el proemdio
	Para i=1 Hasta 20 Hacer
		Notas<- Notas + N[i]
	FinPara
	
	Promedio = Notas/20
	Escribir "el promedio es ",Promedio
	
	EncimaPromedio<-0
	Para i=1 Hasta 20 Hacer
		Si N[i] >= Promedio Entonces
			EncimaPromedio<- EncimaPromedio + 1
			
		FinSi
	FinPara
	Escribir "Las notas encima del promedio son: " ,EncimaPromedio
	
	///Inciso B
	Dimension N[Calif]
	
	Para i=1 Hasta Calif Hacer
		Leer N[i]
	FinPara
	
	Notas<-0  ///Calcular el proemdio
	Para i=1 Hasta Calif Hacer
		Notas<- Notas + N[i]
	FinPara
	
	Promedio = Notas/20
	Escribir "el promedio es ",Promedio
	
	EncimaPromedio<-0
	Para i=1 Hasta Calif Hacer
		Si N[i] >= Promedio Entonces
			EncimaPromedio<- EncimaPromedio + 1
			
		FinSi
	FinPara
	Escribir "Las notas encima del promedio son: " ,EncimaPromedio
	
	
FinAlgoritmo

