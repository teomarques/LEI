.text
	li 	$t1, 100 #control-max
	li 	$t2, 0 #count
	li 	$v0, 0 #soma
	
ciclo:
	
	addi 	$t2, $t2, 1 # i += 1;
	add 	$v0, $v0, $t2  # soma = soma + i;
	
	
	bne 	$t2, $t1, ciclo # if count == 100, break;
	
end:

	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 10
	syscall