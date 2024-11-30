.data
	val: 14
	long: 11
	sec: .word 0,5,7,10,12,15,20,22,30,35,40
	
.text
	lw a0, val
	lw a1, long
	la a2, sec
	
	jal rutina
	addi a7, zero, 10
	ecall
	
	rutina:
		li t0, 4 #valor a restar para desplazar
		#puntero fin de vector t2:
		li t2, 4
		mul t2, t2, a1
		add t2, t2, a2
		#fin puntero fin de vector = t2
		
		
		bucle:
		beq a2, t2, igualpos
			lw t3, (a2) #t3 = valor cargado
			bucle1:
			bgt a0, t3, esmenor #si el valor es menor o igual que el elemento del vector:
				lw t4, -4(t2)
				sw t4, (t2)
				sub t2, t2, t0
				j bucle
			esmenor:
			addi a2, a2, 4
			j bucle
		igualpos:
		sw a0, (t2)
		jr ra