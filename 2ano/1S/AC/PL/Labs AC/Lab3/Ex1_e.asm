.data 

	tab: .byte 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
	
.text 

	li $t0, 0xFFFF0010 # Direito
	li $t1, 0xFFFF0011 # Esquerdo
	li $t2, 9 #counter1
	li $t3, 9 #counter2
	la $s0, tab
	la $s1, tab
	addi $s1, $s1, 1
	addi $s0, $s0, 1

ciclo1:

	lb $t4, 0($s0)
	sb $t4, 0($t0)
	addi $s0, $s0, 1
	addi $t2, $t2, -1
	bne $t2, $zero, ciclo1
	beq $t3, $zero, end
	
ciclo2:

	li $t2, 10  
	la $s0, tab
	addi $t3, $t3, -1
	lb $t5, 0($s1)
	sb $t5, 0($t1)
	addi $s1, $s1, 1
	j ciclo1
	
end: