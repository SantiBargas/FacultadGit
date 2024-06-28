Algoritmo sin_titulo
	cant_de_alumnos_leidos<-0
	VaronesAltos<- 0
	MujeresAltas<- 0
	
	
	Mientras cant_de_alumnos_leidos<4 Hacer
		Escribir "ingrese sexo y altura del alumno M=Masculino F=Femenino"
		Leer sexo, altura
		cant_de_alumnos_leidos<- cant_de_alumnos_leidos + 1
		
		Si sexo= "m" entonces
			//comparar con 1,90
			Si altura>1.90 entonces
				VaronesAltos<- VaronesAltos + 1
			FinSi
		SiNo
			//comparar con 1,75
			Si altura>1.75 entonces
				MujeresAltas<- MujeresAltas + 1
			Finsi
		FinSi
		
	Fin Mientras
	Escribir "La cantidad de varones que superan 1,90m son:" ,VaronesAltos
	Escribir "La cantidad de mujeres que superan 1,75 son:" ,MujeresAltas
FinAlgoritmo
