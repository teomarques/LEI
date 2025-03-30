.text 

ciclo2:
	la $t0, 0xFFFF0010
	li $t1, 0x01
	li $t2, 6
	
ciclo:

	sb $t1, 0($t0)
	sll $t1, $t1, 1
	addi $t2, $t2, -1
	bne $t2, $zero, ciclo
	j ciclo2