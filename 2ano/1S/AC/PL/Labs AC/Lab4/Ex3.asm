.data

	value1: .word 5
	value2: .word 10
	
.text

	lw $a0, value1
	lw $a1, value2
	jal calc
	
end:
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall	

calc:

	sub $v0, $a1, $a0
	bgt $v0, $zero, end
	
trocaSinal:

	li $t0, 0xFFFFFFFF
	xor $v0, $v0, $t0
	addi $v0, $v0, 1
	jr $ra
