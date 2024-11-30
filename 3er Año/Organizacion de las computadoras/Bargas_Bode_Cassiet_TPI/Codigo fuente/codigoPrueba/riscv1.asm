# C�digo de prueba:
# Para probar este c�digo en RARS,
# deber� configurar la memoria como: Compact Data at address 0

# Inicializo tres variables
    addi s0, zero, 3         # a = 3
    addi s1, zero, 1         # b = 1
    addi s2, zero, 16        # cte = 16

# Operaciones l�gicas, aritm�ticas y slt
    or   t0, s0, s1          # c = 3
    and  t1, s0, s1          # d = 1
    add  t2, s0, s1          # e = 4
    sub  t3, s0, s1          # f = 2
    sub  t4, s1, s0          # g = 0xfffffffe = -2
    slt  t5, s0, s1          # h = 0
    slt  t6, s1, s0          # i = 1
    slt  t6, s1, t4          # j = 0

# Un ciclo while usando beq y j
# Inicializo 3 variables
# s2 = 0x10 cte para comparar (16)
    addi t0, zero, 1         # var = 1, variable de trabajo
    addi t1, zero, 0         # cuenta = 0, un contador

while:
    beq  t0, s2, sal1        # Si var == cte, sale del while
    add  t0, t0, t0          # var = var + var
    addi t1, t1, 1           # cuenta = cuenta + 1
    j    while

sal1:
# Al finalizar el ciclo, var debe quedar en 0x10 y cuenta en 4

# Ciclo for
# Inicializo 3 variables
# $t0 = i, $s1 = var

    add  s1, zero, zero      # var = 0, $s0
    #add $s0, $0, 3	     # cte = 3, $s1
    addi t0, zero, 0         # indice = 0, $t0
    addi t1, zero, 10        # veces = 10, $t1

for:
    beq  t0, t1, sal2        # Si indice == veces, branch a sal2
    add  s1, s1, s0          # var = var + cte
    addi t0, t0, 1           # incremento indice
    j    for

sal2:
# Al finalizar el ciclo, var debe quedar en 30 (0x1e) y indice en 10 (0xa)

# Almacenamiento (escritura) con sw
    sw   s0, 0(zero)         # Guarda s0 en registro 0
    sw   s1, 4(zero)         # Guarda s1 en registro 4
    sw   s2, 8(zero)         # Guarda s2 en registro 8

# Carga (lectura) con lw
    lw   t0, 0(zero)         # Carga el valor de registro 0 en t0
    lw   t1, 4(zero)         # Carga el valor de registro 4 en t1
    lw   t2, 8(zero)         # Carga el valor de registro 8 en t2
