Algoritmo parcialito
	HoraCat1 <- 0
	MinutoCat1 <- 0
	SegundosCat1 <- 0
	HoraCat2 <- 0
	MinutoCat2 <- 0
	SegundosCat2 <- 0
	HoraCat3 <- 0
	MinutoCat3 <- 0
	SegundosCat3 <- 0
	TiempCat1 <- 0
	TiempCat2 <- 0
	TiempCat3 <- 0
	GanadorCat1 <- 0
	GanadorCat2 <- 0
	GanadorCat3 <- 0
	CompCat1 <- 0
	CompCat2 <- 0
	CompCat3 <- 0
	Escribir "Recuerde que el numero del competidor no se puede repetir"
	
	Repetir
		Escribir 'Ingrese la categoria'
		Leer Categoria
		Segun Categoria  Hacer
			1:
				CompCat1 <- CompCat1+1
				Escribir 'Ingrese el numero del competidor cat1 y su tiempo'
				Leer Numero
				Leer Hora
				Leer Minutos
				Leer Segundos
				Si Hora<HoraCat1 Entonces
					HoraCat1 <- (Hora*60)*60
					Escribir HoraCat1
					Si Minuto<MinutoCat1 Entonces
						MintuoCat1 <- Minuto*60
						Si Segundos<SegundoCat1 Entonces
							SegundoCat1 <- Segundo
							GanadorCat1 <- Numero
						FinSi
					FinSi
				FinSi
				TiempoCat1 <- (Hora*60)*60+Minutos*60+Segundos
			2:
				CompCat2 <- CompCat2+1
				Escribir 'Ingrese el numero del competidor cat2 y su tiempo'
				Leer Numero
				Leer Hora
				Leer Minutos
				Minutos <- Minutos-60
				Leer Segundos
				Si Hora<HoraCat2 Entonces
					HoraCat2 <- Hora
					Si Minuto<MinutoCat2 Entonces
						MintuoCat2 <- Minuto
						Si Segundos<SegundoCat2 Entonces
							SegundoCat2 <- Segundo
							GanadorCat2 <- Numero
						FinSi
					FinSi
				FinSi
				TiempoCat2 <- (Hora*60)*60+Minutos*60+Segundos
			3:
				CompCat3 <- CompCat3+1
				Escribir 'Ingrese el numero del competidor cat3 y su tiempo'
				Leer Numero
				Leer Hora
				Leer Minutos
				Minutos <- Minutos-120
				Leer Segundos
				Si Hora<HoraCat3 Entonces
					HoraCat3 <- Hora
					Si Minuto<MinutoCat3 Entonces
						MintuoCat3 <- Minuto
						Si Segundos<SegundoCat3 Entonces
							SegundoCat3 <- Segundo
							GanadorCat3 <- Numero
						FinSi
					FinSi
				FinSi
				TiempoCat3 <- (Hora*60)*60+Minutos*60+Segundos
			De Otro Modo:
				Escribir "ingreso una categoria incorrecta, ingrese la categoria nuevamente"
		FinSegun
		Si Hora<MejorHora Entonces
			Si Minuto<MejorMinuto Entonces
				Si Segundos<MejorSegundo Entonces
					GANADORTOTAL <- Numero
				FinSi
			FinSi
		FinSi
	Hasta Que Categoria=0
	
	
	PromedioCat1 <- TiempoCat1/CompCat1
	PromedioCat2 <- TiempoCat2/CompCat2
	PromedioCat3 <- TiempoCat3/CompCat3
	Escribir 'El promedio de tiempo en segundos de la categoria 1 es:',PromedioCat1
	Escribir 'El promedio de tiempo en segundos de la categoria 2 es:',PromedioCat2
	Escribir 'El promedio de tiempo en segundos de la categoria 3 es:',PromedioCat3
	Escribir 'El ganador de la categoria 1 es:' GanadorCat1 'Y su tiempo en segundos es' HoraCat1 MinutoCat1 SegundoCat1
	Escribir 'El ganador de la categoria 2 es:' GanadorCat2  'Y su tiempo en segundos es',HoraCat2 MinutoCat2 SegundoCat2
	Escribir 'El ganador de la categoria 3 es:' GanadorCat3 'Y su tiempo en segundos es' HoraCat3 MinutoCat3 SegundoCat3
	Escribir 'El ganador de la carrera en general es' GANADORTOTAL
FinAlgoritmo
