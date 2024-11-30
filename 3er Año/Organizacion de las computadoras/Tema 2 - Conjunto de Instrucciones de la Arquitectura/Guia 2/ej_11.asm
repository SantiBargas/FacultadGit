.text
	#multiplicar por 17
	li a0, 2
	slli t0, a0, 4 #multiplica por 16
	add a1, a0, t0 #le agrega una vez mas el factor, terminando de multiplicar por 17
	
	#multiplicar por 24
	li a0, 2
	slli t0, a0, 4 #multiplica por 16
	slli t1, a0, 3 #multiplica por 8
	add a1, t0, t1 #le agrega una vez mas el factor, terminando de multiplicar por 17
	