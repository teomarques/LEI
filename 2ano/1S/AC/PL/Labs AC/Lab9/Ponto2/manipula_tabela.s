	.data

	.text
	.globl	manipula_tabela
manipula_tabela:

	# Salvar $ra e $a0 na pilha
	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $a0, 0($sp)

	# Duplicar os valores no array
	move $t0, $a1  # Número de elementos
ciclo_duplicar:
	beq $t0, $zero, prepara_inversao
		lw $t1, 0($a0)  # Carregar valor atual
		sll $t1, $t1, 1 # Duplicar o valor
		sw $t1, 0($a0)  # Salvar no array
		addi $t0, $t0, -1
		addi $a0, $a0, 4 # Avança para o próximo elemento
		j ciclo_duplicar

prepara_inversao:
	# Restaurar $a0 para o início do array
	lw $a0, 0($sp)

	# Chamar a função de inversão
	jal inverte_tabela

	# Restaurar $ra e pilha
	lw $ra, 4($sp)
	addi $sp, $sp, 8

	# Retornar
	jr	$ra
