Algoritmo Ejercicio4_4_a
	Dimension Nombres[8]
	
	Nombres[1]="Perez"
	Nombres[2]="Nisman"
	Nombres[3]="Epeldown"
	Nombres[4]="Garcia"
	Nombres[5]="Solari"
	Nombres[6]="Bargas"
	Nombres[7]="Molas"
	Nombres[8]="Mariño"
	
	Para i = 1 Hasta 8 Hacer
		Si Nombres[i] = "Garcia" Entonces
			Posicion = i
			i=9
		FinSi
	FinPara
	
	Para i = Posicion Hasta 7 Hacer
		Nombres[i] = Nombres[i + 1]
	FinPara
	
	Nombres[8]= "" 
	
	Para i = 1 Hasta 8 Hacer
		
		Escribir "Nombre" ,i," ", Nombres[i]
	FinPara
FinAlgoritmo

