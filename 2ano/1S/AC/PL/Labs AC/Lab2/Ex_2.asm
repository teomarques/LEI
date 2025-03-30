.data
	base_address:	.word 0x10010000	
.text	

.globl main

main:	

	la $s0, base_address
	li $t0, 0x000000FF # Blue
	li $t1, 0x00FF00FF # Magenta
	li $t2, 8192 # Limite !!
	li $t3, 0 #counter
	li $t4, 11 #counter linhas

pintarAzul:

	sw $t0, 0($s0)
	addi $s0, $s0, 4
	addi $t3, $t3, 4
	bne $t3, $t2, pintarAzul
	li $t3, 0
	la $s0, base_address
	add $s0, $s0, 3184
	
pintarMagenta:

	sw $t1, 0($s0)
	addi $s0, $s0, 4
	addi $t3, $t3, 1 # i = i+1
	bne $t3, 8, pintarMagenta
	addi $t4, $t4, 1
	beq $t4, 19, end
	addi $s0, $s0, 224
	li $t3, 0
	j pintarMagenta
	
end:

	li $v0, 10
	syscall
	
	
	
	
	
