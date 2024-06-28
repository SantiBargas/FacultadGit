Algoritmo ejercicio3_8
	TotalMontoCUotas <- 0
	CantidadSocio<- 0
	Escribir 'Juveniles=C1 Vitalicios=C2 Mayores=C3 infantiles= C4 Cadetes=C5'
Repetir
		
	 
	Escribir "Ingrese,la,categoria,DE,socios"
	Leer CategSocio
	Segun 	Categoria Hacer
		C1:
			cuota <- (25*10)/100 
		C2:
			cuota <-  (10*20)/100
		C3:
			cuota <- (10*30)/100	
		C4:
			cuota <- (10*40)/100
		C5:
			cuota <- (25*40)/100
	FinSegun
	TotalMontoCuotas <- TotalMontoCuotas+cuota
	CantidadSocio <- CantidadSocio + 1
	
Hasta Que CantidadSocio=6
Escribir "El monto total de cuotas es" Mostrar, TotalMontoCuotas
FinAlgoritmo
