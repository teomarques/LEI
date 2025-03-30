.data

str: .asciiz "Uma frase!"
comp: .word 0

.text

	la $a0, str
	jal calcLen
	
end:

	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 10
	syscall
	
calcLen:

	li $v0, -1 # Counter
	ciclo:
		lb $t0, 0($a0)
		addi $v0, $v0, 1
		addi $a0, $a0, 1
		bne $t0, $zero, ciclo
	
	jr $ra