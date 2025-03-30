	.data
	
	.text
	.globl	max
	.globl	min
	
max:

	#Codigo da função max aqui!
	
	lw $v0, 0($a0) # Carregar o primeiro elemento
	ciclo_max:
		addi $a1, $a1, -1
		beq $a1, $zero, endFunction_max
		addi $a0, $a0, 4
		lw $t0, 0($a0)
		bgt $v0, $t0, ciclo_max
		move $v0, $t0
		j ciclo_max
		
	endFunction_max:

	jr	$ra

min:

	#Codigo da função min aqui!
	
	lw $v0, 0($a0) # Carregar o primeiro parametro
	ciclo_min:
		addi $a1, $a1, -1
		beq $a1, $zero, endFunction_min
		addi $a0, $a0, 4
		lw $t0, 0($a0)
		bgt $t0, $v0, ciclo_min
		move $v0, $t0
		j ciclo_min
		
	endFunction_min:

	jr	$ra
