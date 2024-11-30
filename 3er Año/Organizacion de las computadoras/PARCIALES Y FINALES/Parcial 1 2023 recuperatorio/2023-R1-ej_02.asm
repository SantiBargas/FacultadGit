.data
	.word 345,457,45,67,456,2425,5876,354,12,23,400,677,44,2344,1123,56,333,112,556,444
	
.text
	jal funcion
	addi a7, zero, 10
	ecall
	
	
	funcion:
	li a0, 0x10010000	#puntero inicio
	addi a1, a0, 80		#puntero fin de vector

	bucle:
	beq a0, a1, finbucle
		addi t0, a0, 4		#puntero que ira recorriendo, inicializado en el siguiente valor
		lw t3, (a0) 		#menor
		add t4, zero, a0 	#direccion del menor
		bucleinterno:
		beq t0, a1, finbucleinterno
			lw t1, (t0)
			bge t1, t3, noesmenor #si es menor:
				add t3, zero, t1 #lo guardo como menor
				add t4, zero, t0 #guardo su direccion
			noesmenor:
			addi t0, t0, 4 #aumento el iterador interno
			j bucleinterno
		finbucleinterno:
		lw t5, (a0) #cargo el valor del iterador externo
		sw t5, (t4) #guardo el valor del iterador externo en la direccion del menor
		sw t3, (a0) #guardo el valor del menor en el iterador externo
		addi a0, a0, 4 #aumento el iterador externo
		j bucle
	finbucle:
	jr ra