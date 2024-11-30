.text
lui t0, 0x12345 
lui t1, 201
lui t2, 0xABCDE


##a) En basic pone los 0 y en source los omite
##b) 
##c)
##d) inicialmente t0 t1 t2 y pc estan en 0
##e) el segmento de datos comienza en address = 10010000
##f) t0 en la primera instruccion toma t0=0x12345000
##g) El registro pc cambia por 00400004 su funcion es ser el contador de programa e ir aumentado de a 4
##h) t1 = 0x000c9000    t2= 0xabcde000  pc= 00400000 , 00400004 00400008 0040000c 00400010