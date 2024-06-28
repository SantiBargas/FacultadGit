Algoritmo sin_titulo
	Leer N
	
	Dimension V[N]	
	
	Para i=1 Hasta N Hacer
		Leer V[i]
		
	FinPara
	
	
	Escribir V[7]
	Escribir V[23]
	Escribir V[N]
	
	DivPor6<-0
	Para i=1 Hasta 8 Hacer
		
		Si V[i] Mod 6 = 0 Entonces
			DivPor6<- DivPor6+1
		SiNo
			Escribir "No hay numeros divisibles por 6"
		FinSi
		
	FinPara
	
	Escribir "Los Numeros Divisibles Por 6 son:" DivPor6
	
FinAlgoritmo
