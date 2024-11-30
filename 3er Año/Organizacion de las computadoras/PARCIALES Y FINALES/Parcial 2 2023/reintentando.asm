.data
	CADENA: .asciz  "Aa1Bb2Cc3{+"
	NUEVACADENA: .space 22  # Espacio para las dos cadenas resultante (ajusta según necesidad)
	
.text

    la a3, NUEVACADENA   # Dirección de la nueva cadena
    li t0, 97            # 'a' - Inicio de minúsculas
    li t1, 122           # 'z' - Fin de minusculas
    li t2, 65            # 'A' - Inicio de mayusculas
    li t3, 90            # 'Z' - Fin de mayusculas
    li t6, 32            # Constante para convertir entre mayúsculas y minúsculas

	
subrutina1:   #Esta subrutina va a recibir cadena y la va a convertir todas las Mayus a Minus
	      la a0, CADENA        # Dirección de la cadena original
	      lb a1,(a0)  	   #Cargamos el primer byte de cadena
	      
	      for1: beqz a1,subrutina2  	#Si el byte es nulo llegamos al fin y vamos a subrutina2
	      	   bge a1,t2,checkMayus		#Si el byte >= 65 puede ser mayuscula
	      	   sb a1,(a3)			#Sino es minuscula, guardamos en la nueva cadena
	      	   addi a3,a3,1			#Incrementamos el puntero de nueva cadena
	      	   addi a0,a0,1			#Incrementamos el puntero de cadena
	      	   lb a1,(a0)			#Cargamos el byte para seguir chequeando
	      	   j for1


subrutina2: 
	 la a0,CADENA  #Volvemos a cargar la direccion de la cadena original
	 lb a1,(a0)
	 
	 for2: beqz a1,fin
	       bge a1,t0 checkMinus
	       sb a1,(a3)
	       addi a3,a3,1
	       addi a0,a0,1
	       lb a1,(a0)
	       j for2      	
	      	           		      	           	
fin: ori a7,x0,10
	ecall	      	           		      	           		      	           	
	      	           		      	           		      	           		      	           		      	           	
checkMayus: ble a1,t3,ESMAYUS
 	    sb a1,(a3)			#Sino es minuscula, guardamos en la nueva cadena
	    addi a3,a3,1		#Incrementamos el puntero de nueva cadena
	    addi a0,a0,1		#Incrementamos el puntero de cadena
	    lb a1,(a0)			#Cargamos el byte para seguir chequeando
	    j for1
ESMAYUS: add a1,a1,t6 			#Sumamos la constante para convertir a minuscula
	 sb a1(a3)
	 addi a3,a3,1
	 addi a0,a0,1
	 lb a1,(a0)
	 j for1   
	 
checkMinus: ble a1,t1,ESMINUS
 	    sb a1,(a3)			#Sino es minuscula, guardamos en la nueva cadena
	    addi a3,a3,1		#Incrementamos el puntero de nueva cadena
	    addi a0,a0,1		#Incrementamos el puntero de cadena
	    lb a1,(a0)			#Cargamos el byte para seguir chequeando
	    j for2
ESMINUS: sub a1,a1,t6 			#Sumamos la constante para convertir a mayuscula
	 sb a1(a3)
	 addi a3,a3,1
	 addi a0,a0,1
	 lb a1,(a0)
	 j for2     	           	      