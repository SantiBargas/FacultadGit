Algoritmo Ejercicio2
	
	Escribir "ingrese cantidad de caudales medidos"
	Leer N
	
	Dimension V[N]
	
	Para i<-1 Hasta N Hacer
		Escribir "ingrese el valor del caudal"
		Leer V[i]
	FinPara
	
	///Inciso A y B
	
	MayorCaudal<-0
	VecesMayor<-0
	Para i<-1 Hasta N Hacer
		
		Si V[i] > MayorCaudal  Entonces
			MayorCaudal<-V[i]
			
		FinSi
		
	FinPara
	
	Para i<-1 Hasta N Hacer
		Si V[i] = MayorCaudal entonces
			VecesMayor<- VecesMayor+1
		FinSi
	FinPara
	Escribir "el mayor caudal es " ,MayorCaudal, "y aparece " ,VecesMayor, " veces "
	
FinAlgoritmo
