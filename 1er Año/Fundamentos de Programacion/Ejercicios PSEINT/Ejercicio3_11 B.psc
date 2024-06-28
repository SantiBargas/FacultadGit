Algoritmo ejercicio3_11
	Escribir 'proceso sin titulo'
	c <- 0
	Suma <- 0
	Mientras c <> 7 Hacer
		Leer x
		c <- c+1
		Si x/2=Trunc(x/2) Entonces
			Suma <- Suma+x
		FinSi
	FinMientras
	
	Escribir ,Suma
FinAlgoritmo

