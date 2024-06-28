Algoritmo sin_titulo
	
	Dimension V[10]
	
	///Poner en 0 para no tener basura en la lista
	Para k<-1 Hasta 10 Hacer
		V[k]<- 0
	FinPara
	
	
	Para i<- 1 Hasta 10 Hacer
		Escribir "ingrese el nro"
		Leer Nro
		
		///Recorro la lista para saber donde poner el numero
		Para k<-1 Hasta 10 Hacer 
			Si V[k] = 0 Entonces
				V[k]<- Nro
				k<-11  ///Ya lo termine asi que fuerzo el cierre del para
			SiNo
				Si V[k]> Nro Entonces
					///K es la posicion a insertar el num, corro todo a la derecha
					
					Para j<-10 Hasta k+1 con paso -1 Hacer
						V[j] <- V[j - 1]
					FinPara
					
					V[k] <- Nro
					K<-11  ///Ya lo termine asi que fuerzo el cierre del para
				FinSi
			FinSi
		FinPara
	FinPara
	
	
	
	
	Para k<-1 Hasta 10 hacer
		
		Escribir V[k]
		
	FinPara

FinAlgoritmo
