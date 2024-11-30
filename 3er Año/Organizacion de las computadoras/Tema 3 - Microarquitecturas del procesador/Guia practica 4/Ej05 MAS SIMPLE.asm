.data
	v1: .word 1
	v2: .word 2
	v3: .word 3

.text
	lw t2, v2
	lw t3, v3
	
	lw t0, v1 # t0 = menor
	
	bge t2, t0, t2noesmenor
	add t0, zero, t2
	t2noesmenor:
	
	bge t3, t0, t3noesmenor
	add t0, zero, t3
	t3noesmenor:
	
	la t6, v3
	sw t0, 4(t6)
