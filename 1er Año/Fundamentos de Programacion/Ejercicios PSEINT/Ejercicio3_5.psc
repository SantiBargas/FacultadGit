Algoritmo ejercicio3_5
	Escribir "ingresar un valor" 

	Leer x
	
	Si x<1 Entonces
		Escribir "si x es menor a 1 se realiza la operacion x elevado a la 2"
		x <- x^2
	SiNo
		Escribir "si x es mayor o igual a 1 se realiza la operacion x +3"
		Si x>=1 Entonces
			x<-x+3
		FinSi
	FinSi
	mostrar x 
FinAlgoritmo
