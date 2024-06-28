Algoritmo Ejercicio4_4_b
	Dimension Nombres[8]
	
	Nombres[1]="Perez"
	Nombres[2]="Nisman"
	Nombres[3]="Epeldown"
	Nombres[4]="Garcia"
	Nombres[5]="Solari"
	Nombres[6]="Bargas"
	Nombres[7]="Molas"
	Nombres[8]=""
	
	Escribir "Ingrese el apellido"
	Leer Apellido
	Escribir "Ingrese posicion en donde insertar"
	Leer Posicion
	
	Para i = 8 Hasta Posicion con paso -1  Hacer
		Nombres[i] = Nombres[i - 1]
		
	FinPara
	
	Nombres[Posicion]=Apellido
	Para i = 1 Hasta 8 Hacer
		
		Escribir "Nombre" ,i," ", Nombres[i]
	FinPara
FinAlgoritmo
	

