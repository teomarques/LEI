.data
	base_address:	.word 0x10010000	
.text	

.globl main

main:

	la $s0, base_address
	li $t0, 0x00000000  # cor variavel
	li $t1, 0 # Vermelho
	li $t2, 0 # Verde
	li $t3, 0 # Counter-Linha
	li $t4, 0 # Counter-Coluna
	li $t5, 2048 # Limite
	li $t6, 0 # Counter I
	
	
ciclo:

	mul $t1, $t3, 4
	mul $t2, $t4, 4
	sll $t1, $t1, 16
	sll $t2, $t2, 8
	or $t0, $t1, $t2
	sw $t0, 0($s0)
	addi $s0, $s0, 4
	addi $t6, $t6, 1
	addi $t4, $t4, 1
	beq $t4, 64, mudaLinha
	bne $t6, $t5, ciclo
	
mudaLinha:

	li $t4, 0
	addi $t3, $t3, 1
	beq $t3, 32, end
	j ciclo
	
end:

	li $v0, 10
	syscall
	