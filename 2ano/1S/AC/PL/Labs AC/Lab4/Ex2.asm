.data

str: .asciiz "socorro"
c1: .byte 'r'
c2: .byte 'a'

.text

	la $a0, str
	jal trocaC

end:
	move $t0, $v0
	
	li $v0, 4
	la $a0, str
	syscall
	
	move $a0, $t0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
trocaC:
	lb $t1, c1
	lb $t2, c2
	li $v0, 0
	ciclo:
		
		lb $t0, 0($a0)
		addi $a0, $a0, 1
		beq $t0, $t1, troca
		bne $t0, $zero, ciclo
		jr $ra
		
	troca:
		sb $t2, -1($a0)
		addi $v0, $v0, 1
		j ciclo
	