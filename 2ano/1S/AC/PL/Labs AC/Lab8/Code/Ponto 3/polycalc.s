        .data

        .text
        .globl  polycalc
polycalc:
    
    lw $t0, 16($sp) # Dar load ao x5
    
    add $t1, $a0, $a1	# Aqui � feito (x1 + x2)
    mul $t1, 5 				# Aqui � feito 5(x1+x2)
    
    mul $t0, $t0, $a3 # Aqui � x4 * x5
    mul $t0, -3				# Aqui � -3 * (x4 * x5)
    add $t0, $a2, $t0 # Aqui � x3 - o anterior
    
    mul $v0, $t1, $t0 # Multiplicar as duas parcelas

    
    jr $ra                   # Retorna ao chamador
