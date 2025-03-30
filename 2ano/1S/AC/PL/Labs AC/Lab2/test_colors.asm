.data
	base_address:	.word 0x10010000	
.text	

.globl main

main:	

	la $s0, base_address	
	li $t0, 0	# counter colunas
	li $t1, 0	# counter-linhas
	li $t3, 136 	# step forward
	li $t2, 0x00FFFF00 # amarelo
	
pintarLinha:

	sw $t2, 0($s0)
	addi $s0, $s0, 4
	addi $t0, $t0, 1
	bne $t0, 30, pintarLinha
	j contaColuna
	
contaColuna:

	add $s0, $s0, $t3
	addi $t1, $t1, 1
	li $t0, 0
	bne $t1, 20, pintarLinha

	
	