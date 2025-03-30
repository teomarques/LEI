	.data
	
	.text
	.globl	max
	.globl	min
	
max:

	#Codigo da função max aqui!
	
	lw $v0, 0($a0)
	li $t0, 0
	addi $a1, $a1, -1
	addi $a0, $a0, 4
	ciclo_max:
		beq $t0, $a1, endFunction_max
		lw $t1, 0($a0)
		addi $a0, $a0, 4
		addi $t0, $t0, 1
		bgt $t1, $v0, atualizaV0_max
	 	j ciclo_max
	atualizaV0_max:
		move $v0, $t1
		j ciclo_max
		
	endFunction_max:
 	
 	# END FUNCTION with v0 with max value
	jr	$ra

min:

	#Codigo da função min aqui!
	
	lw $v0, 0($a0)
	li $t0, 0
	addi $a1, $a1, -1
	addi $a0, $a0, 4
	ciclo_min:
		beq $t0, $a1, endFunction_min
		lw $t1, 0($a0)
		addi $a0, $a0, 4
		addi $t0, $t0, 1
		bgt $v0, $t1, atualizaV0_min
	 	j ciclo_min
	atualizaV0_min:
		move $v0, $t1
		j ciclo_min
		
	endFunction_min:
 	
 	# END FUNCTION with v0 with max value

	jr	$ra
