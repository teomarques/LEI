	.data
	
	.text
	.globl	max
	.globl	min
	
max:

	#Codigo da função max aqui!
	
	move $v0, $a0
	# Verifica a1
	bgt $v0, $a1, continue_max
	move $v0, $a1
	continue_max:
	# Verifica a2
	bgt $v0, $a2, continue2_max
	move $v0, $a2
 	continue2_max:
 	#Verifica a3
 	bgt $v0, $a3, continue3_max
 	move $v0, $a3
 	continue3_max:
 	
 	# END FUNCTION with v0 with max value

	jr	$ra

min:

	#Codigo da função min aqui!
	
	move $v0, $a0
	# Verifica a1
	bgt $a1, $v0, continue_min
	move $v0, $a1
	continue_min:
	# Verifica a2
	bgt $a2, $v0, continue2_min
	move $v0, $a2
 	continue2_min:
 	#Verifica a3
 	bgt $a3, $v0, continue3_min
 	move $v0, $a3
 	continue3_min:
 	
 	# END FUNCTION with v0 with max value

	jr	$ra
