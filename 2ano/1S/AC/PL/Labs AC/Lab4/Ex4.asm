.data

	value:  .word 0x12345678

.text

	lw $a0, value
	jal trocaBits
	
end:

	move $a0, $v0
	li $v0, 34
	syscall
	li $v0, 10
	syscall
	
trocaBits:

	and $t0, $a0, 0xFF # t0 = 0x40
	srl $a0, $a0, 8
	and $t1, $a0, 0xFF # t1 = 0x30
	srl $a0, $a0, 8
	and $t2, $a0, 0xFF # t2 = 0x20
	srl $a0, $a0, 8
	li $v0, 0x00000000
	sll $t0, $t0, 24
	sll $t1, $t1, 16
	sll $t2, $t2, 8
	or $v0, $v0, $t0
	or $v0, $v0, $t1
	or $v0, $v0, $t2
	or $v0, $v0, $a0
	jr $ra
	