Algoritmo ejercicio3_11
	Escribir 'proceso sin titulo'
	c <- 0
	Suma <- 0
	Repetir
		Leer x
		c <- c+1
		Si x/2=Trunc(x/2) Entonces
			Suma <- Suma+x
		FinSi
	Hasta Que c=7
	Escribir ,Suma
FinAlgoritmo
