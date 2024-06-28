Algoritmo sin_titulo
	
	 ///Inciso A
	Dimension V[3]	
	
	Para i=1 Hasta 3 Hacer
		Escribir "ingrese los apellidos"
		Leer V[i]
	FinPara
	
	Cantidad<-0 //Se usa para saber si hay garcia o no
	Para i=1 Hasta 3 Hacer
		Si V[i] = "GARCIA" Entonces
			Cantidad<- Cantidad + 1
			Escribir "Hay un garcia en la posicion ",i
		FinSi
	FinPara
	
	Si Cantidad = 0 Entonces
		Escribir "No hay ningun Garcia"
	SiNo
		Escribir "hay Garcia"
	FinSi
	
	///Inciso B
	Dimension Z[3]	
	
	Para i=1 Hasta 3 Hacer
		Escribir "ingrese los apellidos"
		Leer Z[i]
	FinPara
	
	Cantidad<-0 //Se usa para saber si hay garcia o no
	Para i=1 Hasta 3 Hacer
		Si Z[i] = "GARCIA" Entonces
			Cantidad<- Cantidad + 1
			Si Cantidad=1 Entonces
				Escribir "El 1 er garcia esta en la posicion ",i
			FinSi
		FinSi
	FinPara
	
	Si Cantidad = 0 Entonces
		Escribir "No hay ningun Garcia"
	FinSi
	
	///Otra forma de resolver inciso B 
	
	Dimension U[6]
	
	Para i=1 Hasta 6 Hacer
		Escribir "Ingrese los apellidos"
		Leer U[i]
	FinPara
	
	Posicion<-1
	Mientras Posicion <=6 y U[P] <> "GARCIA" Hacer
		Posicion<- Posicion +1
	FinMientras
	
	Si P<=6 Entonces
		Escribir "Garcia esta en " ,Posicion
	SiNo
		Escribir "No Hay Garcia"
	FinSi
	
	
FinAlgoritmo
