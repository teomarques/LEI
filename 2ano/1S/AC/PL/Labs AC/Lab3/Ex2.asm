.data 

	tab: .byte 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
	tabL: .byte 0x11, 0x21, 0x41, 0x81, 0x12, 0x22, 0x42, 0x82, 0x14, 0x24, 0x44, 0x84, 0x18, 0x28, 0x48, 0x88

.text
	
	li $t6, 0xFFFF0010   # Direito
	li $t0, 0xFFFF0012   # Endereço para enviar a linha a ser scaneada
    	li $t1, 0xFFFF0014   # Endereço para ler o valor da tecla pressionada
    	la $s0, tab	# Tab Bytes
    	la $s1, tabL	# Tab Nºs
    	li $t2, -1 # N_Linhas
    	li $t3, 0 # Numero Lido
    	li $t9, 0x11
    	
leLinhas:
	addi $t2, $t2, 1
	sb $t2, 0($t0)
    	lb $t3, 0($t1)
	beq $t3, $zero, leLinhas
    	li $t4, -1 # counter
    	
procuraTab:

	lb $t5, 0($s1)
	addi $s1, $s1, 1
	addi $t4, $t4, 1
	bne $t5, $t3, procuraTab
	beq $t5, $t9, zero
    	
ciclo:

	addi $s0, $s0, 1
	addi $t4, $t4, -1
	bne $zero, $t4, ciclo
	lb $t4, 0($s0)
	sb $t4, 0($t6)
	j end
	
zero:

	lb $t4, 0($s0)
	sb $t4, 0($t6)

end:
