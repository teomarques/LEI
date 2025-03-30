		.data

		.text
		.globl	polycalc
polycalc:

	# Codigo da função aqui
	
	lw $t0, 16($sp) # Carregar o valor de a5 // tem de ser a posição 16 pois a posição 0, 4, 8 e 12 já têm os valores de a0, a1, a2 e a3 respetivamente
	
	add $t1, $a0, $a1
	mul $t1, 5  		# Nestas duas linhas, eu calculo 5(x1 + x2)
	
	mul $t0, -3
	mul $t0, $a3
	add $t0, $a2, $t0 # Nestas três linhas, eu calculo (x3 - 3 * x4 * x5)
	
	mul $v0, $t0, $t1

	jr	$ra
