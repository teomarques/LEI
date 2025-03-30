.text

	li $v0, 5
	syscall
	move $t0, $v0 # Numero Introduzido = t0
	li $t3, 1
	move $t2, $t0
fatorial:
	
	addi $t2, $t2, -1
	mul $t0, $t0, $t2
	bne $t2, $t3, fatorial
	
end:
	
	li $v0, 1
	move $a0, $t0
	syscall
	li $v0, 10
	syscall