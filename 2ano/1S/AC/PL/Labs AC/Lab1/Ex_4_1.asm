.text

	li $v0, 5
	syscall
	move $t7, $v0
	li $t0, 3 # Aux - Multiplicação
	li $t2, 0 # i = 0
	
multi:

	add $t1, $t1, $t7
	addi $t2, $t2, 1
	bne $t2, $t0, multi
	
	addi $t1, $t1, -1
	li $t2, 0
	li $v0, 1
	
ciclo:

	addi $t2, $t2, 1
	move $a0, $t2
	syscall
	bne $t2, $t1, ciclo
	
end:

	li $v0, 10
	syscall
