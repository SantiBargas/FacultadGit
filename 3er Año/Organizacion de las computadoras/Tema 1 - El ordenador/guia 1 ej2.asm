.text
lui a1, 0x10010 # (load upper inmediate) Carga el valor inmediato 0x10010 en la parte superior de a1
lw t0, 0(a1) #(load word) en t0 guarda a1
lw t1, 4(a1)
lw t2, 8(a1)


#carga tres palabras consecutivas de memoria a partir de la direcci�n 0x10010000 
#en los registros t0, t1 y t2

#lw t1, 4(a1) carga una palabra de 32 bits desde la direcci�n a1 + 4 en el registro t1.

#Si a1 fuera 0x10010004, la instrucci�n lw t1, 0(a1) 
##cargar�a el valor desde la direcci�n 0x10010004, que ser�a el mismo valor que se carga con 
##lw t1, 4(a1) cuando a1 es 0x10010000. Por lo tanto, s�, se obtendr�a el mismo resultado porque ambas instrucciones estar�an cargando desde la misma direcci�n de memoria.