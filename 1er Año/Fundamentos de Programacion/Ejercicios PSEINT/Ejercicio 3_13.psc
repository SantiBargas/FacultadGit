Algoritmo sin_titulo
	numeros <- 0
	Mayor <- 0
	Mientras numeros<20 Hacer
		UnDato <- azar(100)
		Escribir ,UnDato
		Si UnDato>Mayor Entonces
			Mayor <- UnDato
		FinSi
		numeros <- numeros+1
	FinMientras
	Escribir 'el mayor es',Mayor
FinAlgoritmo
