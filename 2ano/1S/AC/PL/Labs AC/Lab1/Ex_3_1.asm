.data
	tab: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	
.text

	la 	$s0, tab
	
	li 	$t0, 10 # n_max
	li 	$t1, 0 # Soma
	li 	$t3, 0 # i
	
ciclo:
	
	lw	$t2, 0($s0)
	add $t1, $t1, $t2
	addi $s0, $s0, 4
	addi $t3, $t3, 1
	bne $t3, $t0, ciclo
	
end:

	move $a0, $t1
	li $v0, 1
	syscall
	li $v0, 10
	syscall
	