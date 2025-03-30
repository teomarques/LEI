.data 

	tab: .byte 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
	
.text 

	li $t6, 0xFFFF0010   # Direito
	li $t0, 0xFFFF0012   # Endereço para enviar a linha a ser scaneada
    	li $t1, 0xFFFF0014   # Endereço para ler o valor da tecla pressionada
    	la $s0, tab	# Tab Bytes
    	li $t2, -1 # N_Linhas
    	li $t3, 0 # Numero Lido
    	
leLinhas:
	addi $t2, $t2, 1
	sb $t2, 0($t0)
    	lbu $t3, 0($t1)
	beq $t3, $zero, leLinhas
    	
calcNum:
	li $t2, 4
	sll $t4, $t3, 28 # linha
	srl $t4, $t4, 28 # linha
	srl $t4, $t4, 1 # linha
	srl $t5, $t3, 4 # coluna
	srl $t5, $t5, 1 # coluna
	beq $t4, $t2, corrigeLinha
	j continue
	
corrigeLinha:

	addi $t4, $t4, -1
	
continue:

	beq $t5, $t2, corrigeColuna
	j continue2
	
corrigeColuna:

	addi $t5, $t5, -1

continue2:

	sll $t4, $t4, 2
	add $t4, $t4, $t5 # t4 passa a ser o valor final

	beq $t4, $zero, zero

ciclo:

	addi $s0, $s0, 1
	addi $t4, $t4, -1
	bne $t4, $zero, ciclo
	lbu $t2, 0($s0)
	sb $t2, 0($t6)
	
zero:

	lb $t2, 0($s0)
	sb $t2, 0($t6)