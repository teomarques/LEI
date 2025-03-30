	.data
	
	.text
	.globl	conta_char
	
conta_char:

	#Codigo da função aqui!
	li $v0, 0
	ciclo:
		lb $t0, 0($a0)
		beq $t0, $zero, endFunction
		addi $a0, $a0, 1
		beq $t0, $a1, addV0
		j ciclo
		
	addV0:
		addi $v0, $v0, 1
		j ciclo
		
	endFunction:

	jr	$ra
