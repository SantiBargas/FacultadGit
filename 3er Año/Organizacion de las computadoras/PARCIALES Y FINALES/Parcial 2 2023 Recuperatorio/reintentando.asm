.data
	val: .word  45
	long: .word  11
	sec: .word 0,5,7,10,12,15,20,22,30,35,40
	resultado: .space 44

.text
	la a0,val
	lw a0,(a0)
	
	la a1,long
	lw a1,(a1)
	
	la a2,sec
	la t0,resultado
	li a3,0
	for : beq a3,a1,copy_fin
	      lw a4,(a2)
	      bge a4,a0,insertar  # 14 > 12
	      sw a4,(t0)   #guardamos en nuevo vector
	      addi a3,a3,1
	      addi a2,a2,4
	      addi t0,t0,4
	      j for
	
		insertar: sw a0,(t0)  #insertamos en nuevo vector
			  addi t0,t0,4 #movemos el puntero
			  sw a4,(t0) #guardamos 15
			  addi a2,a2,4 #movemos al siguiente valor
			    addi t0,t0,4 #movemos el puntero
			  addi a3,a3,1 #incrementamos el contador pq se guardo el 15
			  j copy_rest
		
		copy_rest:beq a3,a1,fin
			  lw a4,(a2)
			  sw a4,(t0)
			  addi a2,a2,4
			  addi t0,t0,4
			  addi a3,a3,1
			  j copy_rest
	
		copy_fin: sw a0,(t0)
			  j fin
			 
	fin: ori a7,x0,10
		ecall
		