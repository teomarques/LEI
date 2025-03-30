.data 

	tab: .byte 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
	
.text

	li $t0, 0xFFFF0010 # Direito
	li $t1, 0xFFFF0011 # Esquerdo
	li $t2, 16 #counter display 1
	li $t3, 15 #counter display 2
	la $s0, tab
	la $s1, tab
	lb $t5, 0($s0)
	sb $t5, 0($t1)
	
ciclo1:

	lb $t4, 0($s0)
	sb $t4, 0($t0)
	addi $s0, $s0, 1
	addi $t2, $t2, -1
	bne $t2, $zero, ciclo1
	j ciclo2
	
ciclo2:

	la $s0, tab
	li $t2, 16
	addi $s1, $s1, 1
	addi $t3, $t3, -1
	lb $t5, 0($s1)
	sb $t5, 0($t1)
	beq $t3, $zero, end
	j ciclo1
	
end: