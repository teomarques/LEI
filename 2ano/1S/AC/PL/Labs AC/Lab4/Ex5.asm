.data

	num: .word 0xF0F0F0F0 # 00000000 00000000 11111111 10101010
	
.text
 	lw $a0, num
 	jal contaBits
 	
 	beq $v0, $zero, fimpar
 	j fimimpar

fimpar:

	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 10
	syscall

fimimpar:

	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 10
	syscall	
 	
contaBits:

 	 li $t1, 0 # counter
 	 li $v0, 0 # counter-1s
 	 li $t5, 32
 	 
 	 ciclo:
 	 	beq $t1, $t5, endFun
 	 	li $t0, 0x00000001
 	 	sllv $t3, $t0, $t1
 	 	and $t3, $t3, $a0
 	 	addi $t1, $t1, 1 # aumentar counter
 	 	
		bne $t3, $zero, aumentaCounter
		j ciclo
		
	aumentaCounter:

		addi $v0, $v0, 1
		j ciclo
	
	endFun:
		jr $ra
		#li $t0, 0x00000001
		#and $t3, $t0, $v0
		#beq $t3, $t0, impar
		#j par
		#impar:
		#	jr $ra
		#par: 
		#	li $v0, 0
		#	jr $ra
 	 	
