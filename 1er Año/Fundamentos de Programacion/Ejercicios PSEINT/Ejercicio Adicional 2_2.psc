Algoritmo sin_titulo
	
	Dimension V[20]
	
	InicioPares<- 1
	InicioImpares<- 20
	
	Para i<-1 hasta 20 Hacer
		Nro<- 100 + azar(700)
		
		Si Nro%2 = 0 Entonces
			
			V[InicioPares]<- Nro
			InicioPares <- InicioPares+1
		SiNo
			V[InicioImpares]<-Nro
			InicioImpares<- InicioImpares - 1
		FinSi
	FinPara
	
	Para i<- 1 Hasta 20 Hacer
		Escribir V[i] ," " Sin Saltar
	FinPara
FinAlgoritmo
