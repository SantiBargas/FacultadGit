Algoritmo sin_titulo
	AlumnosTotal <- 0
	
	EdadMayor<- 1
	
	
	Repetir
		Escribir 'ingrese el nombre y apellido de un alumno'
		Leer Alum
		Escribir 'Ingrese la edad del alumno'
		Leer Edad
		
		  Si Edad>EdadMayor Entonces
		      EdadMayor<- Edad
		  FinSi
		  
		AlumnosTotal <- AlumnosTotal+1
	Hasta Que AlumnosTotal=5
	Escribir EdadMayor
FinAlgoritmo
