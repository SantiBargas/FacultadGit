Algoritmo ejercicio3_9
	//En algebra estan disponibles las comisiones 1, 2, 3, 4 y 5
	Alumnos<- 0
	AlumCom1<- 0
	AlumCom2<-0
	AlumCom3<-0
	AlumCom4<-0
	AlumCom5<-0
	
	NotaCom1<-0
	NotaCom2<-0
	NotaCom3<-0
	NotaCom4<-0
	NotaCom5<-0
	Repetir
		
		Escribir "ingrese la comision del alumno"
		Leer Comision
		Segun Comision Hacer
			1:
				AlumCom1<- AlumCom1 +1
				Escribir "ingrese la calificacion del alumno"
				Leer Nota
				NotaCom1<- NotaCom1+ Nota
			2:
				AlumCom2<- AlumCom2 +1
				Escribir "ingrese la calificacion del alumno"
				Leer NOTA
				NotaCom2<- NotaCom2+ Nota
			3:
				AlumCom3<- AlumCom3+1
				Escribir "ingrese la calificacion del alumno"
				Leer NOTA
				NotaCom3<- NotaCom3+ Nota
			4:
				AlumCom4<- AlumCom4+1	
				Escribir "ingrese la calificacion del alumno"
				Leer NOTA
				NotaCom4<- NotaCom4+ Nota
			5:
				AlumCom5<- AlumCom5 +1
				Escribir "ingrese la calificacion del alumno"
				Leer NOTA
				NotaCom5<- NotaCom5+ Nota
		FinSegun
		Alumnos<- Alumnos + 1
		
	Hasta Que Alumnos=24
	
	PromedioCom1<- NotaCom1/AlumCom1
	PromedioCom2<-NotaCom2/AlumCom2
	PromedioCom3<-NotaCom3/AlumCom3
	PromedioCom4<-NotaCom4/AlumCom4
	PromedioCom5<-NotaCom5/AlumCom5
	Escribir "El promedio de Com1 son", PromedioCom1
	Escribir "El promedio de Com2 son", PromedioCom2
	Escribir "El promedio de Com3 son", PromedioCom3
	Escribir "El promedio de Com4 son", PromedioCom4
	Escribir "El promedio de Com5 son", PromedioCom5
	
FinAlgoritmo
