.data 

	tab: .byte 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71


.text 

	li $t0, 0xFFFF0010 # Direito
	li $t1, 5
	la $s0, tab
	li $t2, 0 # count
	beq $t1, $zero, zero
ciclo:

	addi $s0, $s0, 1
	addi $t1, $t1, -1
	bne $t2, $t1, ciclo
	lb $t3, 0($s0)
	sb $t3, 0($t0)
	
zero:

	lb $t3, 0($s0)
	sb $t3, 0($t0)
	
