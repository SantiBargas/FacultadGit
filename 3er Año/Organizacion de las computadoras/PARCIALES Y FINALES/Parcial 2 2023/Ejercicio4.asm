.data
	CADENA: .asciz  "Aa1Bb2Cc3{+"
	NUEVACADENA: .space 11  # Espacio para la cadena resultante (ajusta según necesidad)
	
.text
    la a0, CADENA        # Dirección de la cadena original
    la a3, NUEVACADENA   # Dirección de la nueva cadena
    li t0, 97            # 'a' - Inicio de minúsculas
    li t1, 122           # 'z' - Fin de minusculas
    li t2, 65            # 'A' - Inicio de mayusculas
    li t3, 90            # 'Z' - Fin de mayusculas
    li t6, 32            # Constante para convertir entre mayúsculas y minúsculas

	
			
	subrutina1: lb a1,(a0) #Cargamos el byte
		    beqz a1,subrutina2 #Si es nulo llegamos al final
		    bge a1,t0,CheckMinus # si a1 es mayor a 97 chequeamos si es minus
		    j guardar1			
	
	subrutina2:
		 la a0,CADENA #Volvemos a leer la cadena original
		 for2: lb a1,(a0) #Cargamos el byte
		      beqz a1,fin #Si es nulo llegamos al final
		      bge a1,t2,CheckMayus # si a1 es mayor a 65 chequeamos si es mayus
		      j guardar2	

	fin: ori a7,x0,10
	     ecall                # Salir del programa

#######################CHEQUEOS MINUSCULA Y MAYUSCULA#####################################
CheckMinus: ble a1,t1,SIESMINUS #a1 menor o igual a 122 es mayuscula
	    j guardar1 		#Si no es minuscula, guardamos el byte
SIESMINUS:  sub a1,a1,t6 	# Convertir de minuscula a mayuscula
	    j guardar1 		#Guardamos en la nueva cadena

CheckMayus: ble a1,t3,SIESMAYUS #a1 menor o igual a 122 es mayuscula
	    j guardar2 		#Si no es mayus, guardamos el byte
SIESMAYUS:  add a1,a1,t6 	# Convertir de mayúscula a minúscula
	    j guardar2 		#Guardamos en la nueva cadena
##########################################################################
			
guardar1: sb a1,(a3) 		# Guardar el carácter en NUEVACADENA
	 addi a0,a0,1 		# Avanzar el puntero de la cadena origina
	 addi a3,a3,1           # Avanzar el puntero de la nueva cadena
	 j subrutina1		# Repetir para el siguiente carácter
	 
guardar2: sb a1,(a3) 		# Guardar el carácter en NUEVACADENA
	 addi a0,a0,1 		# Avanzar el puntero de la cadena origina
	 addi a3,a3,1           # Avanzar el puntero de la nueva cadena
	 j for2		# Repetir para el siguiente carácter

