		.data

		.text
		.globl	polycalc
polycalc:

	# Codigo da fun��o aqui
	
	lw $t0, 16($sp) # Carregar o valor de a5 // tem de ser a posi��o 16 pois a posi��o 0, 4, 8 e 12 j� t�m os valores de a0, a1, a2 e a3 respetivamente
	
	add $t1, $a0, $a1
	mul $t1, 5  		# Nestas duas linhas, eu calculo 5(x1 + x2)
	
	mul $t0, -3
	mul $t0, $a3
	add $t0, $a2, $t0 # Nestas tr�s linhas, eu calculo (x3 - 3 * x4 * x5)
	
	mul $v0, $t0, $t1

	jr	$ra
