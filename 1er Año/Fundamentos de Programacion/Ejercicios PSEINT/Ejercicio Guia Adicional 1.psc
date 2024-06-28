Algoritmo sin_titulo
	Dimension Apellidos[10]
	
	Apellidos[1] <- "ALVAREZ"
	Apellidos[2] <- "BENIEZ"
	Apellidos[3] <- "BOGADO"
	Apellidos[4] <- "CACERES"
	Apellidos[5] <- "CORIA"
	Apellidos[6] <- "FERNANDEZ"
	Apellidos[7] <- "GAUNA"
	Apellidos[8] <- "GONZALEZ"
	Apellidos[9] <- "GUTIERREZ"
	Apellidos[10] <- ""
	
	Leer Ape 
	
	Para i<-1 Hasta 10 Hacer
		Si Apellidos[i] = "" Entonces
			Apellidos[i]<- Ape
		SiNo
			
			Si Ape < Apellidos[i] Entonces
				Para j<- 10 Hasta i+1 con paso -1 Hacer
				Apellidos[j] <- Apellidos [j - 1]
				FinPara
				Apellidos[i]<- Ape
				i<- 11
			FinSi
			
		FinSi
		
	FinPara

	
	
	Para i<-1 Hasta 10 Hacer
		Escribir Apellidos[i]
	FinPara
finAlgoritmo


