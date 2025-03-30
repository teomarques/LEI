	.data
	
	.text
	.globl	max
	.globl	min
	
max:

	#Codigo da função max aqui!
	
	move $v0, $a0 # Recolher primeiro parametro
	bgt $v0, $a1, continue_max
	move $v0, $a1 # Atualizar caso a1 seja maior
	continue_max:
	bgt $v0, $a2, continue2_max
	move $v0, $a2 # Atualizar caso a2 seja maior
	continue2_max:
	bgt $v0, $a3, continue3_max
	move $v0, $a3
	continue3_max:

	jr	$ra

min:

	#Codigo da função min aqui!
	
 	move $v0, $a0 # Recolher primeiro parametro
	bgt $a1, $v0, continue_min
	move $v0, $a1 # Atualizar caso a1 seja menor
	continue_min:
	bgt $a2, $v0, continue2_min
	move $v0, $a2 # Atualizar caso a2 seja maior
	continue2_min:
	bgt $a3, $v0, continue3_min
	move $v0, $a3
	continue3_min:

	jr	$ra
