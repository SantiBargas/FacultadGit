Algoritmo sin_titulo
	Dimension Pares[20]
	Dimension Impares[20]
	
	SumaPares<- 0	
	SumaImpares<- 0
	ConteoImpares<-0
	ConteoPares<-0
	
	Para i<-1 hasta 20 Hacer
		Num<- azar(700)
		
		Si Num%2 = 0 Entonces
			ConteoPares<- ConteoPares +1
			Pares[ConteoPares]<-Num
			SumaPares<- SumaPares+Num
		SiNo
			ConteoImpares<- ConteoImpares+1
			Impares[ConteoImpares]<- Num
			SumaImpares<- SumaImpares+ Num
		FinSi
	FinPara
	
	Si ConteoPares > 0 Entonces
		Para i<-1 hasta ConteoPares hACER
			
			Escribir Pares[i], " " Sin Saltar
		FinPara
		Escribir ""
		Escribir "El prom de pares es" ,SumaPares/ConteoPares
	FinSi
	
	Si ConteoImpares > 0 Entonces
		Para i<-1 hasta ConteoImpares Hacer
			
			Escribir Impares[i], " " Sin Saltar
		FinPara
		Escribir ""
		Escribir "El prom de IMPpares es" ,SumaIMPares/ConteoIMPares
	FinSi
	
FinAlgoritmo
