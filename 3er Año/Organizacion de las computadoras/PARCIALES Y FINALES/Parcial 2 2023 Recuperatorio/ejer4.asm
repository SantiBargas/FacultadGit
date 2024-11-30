.data
	val: .word  45
	long: .word  11
	sec: .word 0,5,7,10,12,15,20,22,30,35,40
	resultado: .space 44

.text

	lw t0,val	#Valor a insertar
	lw t1,long	#Longitud del vector
	la a0,sec       #Direccion del vector
	la a1,resultado #Direccion del nuevo vector
	li t2,0 	#Contador para el vector
	
	for: beq t2,t1,copy_fin #Si no encontramos antes, lo guardamos a lo ultimo
	     lw a2,(a0) #Cargamos el valor del vector
	     bgt a2,t0,valor_correcto # 15 > 14 Debemos guardar 14
	     sw a2,(a1) #Guardamos el valor del vector en el nuevo
	     addi a0,a0,4 #Avanzamos el vector original
 	     addi a1,a1,4 #Avanzamos el nuevo vector
	     addi t2,t2,1 #Incrementamos el contador
	     j for
	

	valor_correcto: sw t0,(a1) #Guardamos el valor a insertar en el nuevo vector
			addi a1,a1,4 #Incrementamos el nuevo vector
			j copy_rest

	copy_rest: beq t2,t1,fin
		   lw a2,(a0) #Cargamos el valor del vector
		   sw a2,(a1) #Guardamos el valor del vector en el nuevo
		   addi a0,a0,4 #Avanzamos el vector original
 	           addi a1,a1,4 #Avanzamos el nuevo vector
 	           addi t2,t2,1 #Incrementamos el contador
 	           j copy_rest
 	 
 	 copy_fin: sw t0,(a1) #Guardamos el valor del vector en el nuevo
 	 	   j fin
				
	fin: ori a7,x0,10
	     ecall