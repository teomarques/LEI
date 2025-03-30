.data
	tab: .word 10,20,30,40



.text
	la	$s0, tab

	
	li	$t1,4
	li	$t2,0 # I
	li	$t3,0 # Soma
	
ciclo:	
	lw	$t0,0($s0)
	add	$t3,$t3,$t0
	addi	$t2,$t2,1	# I=I+1
	
	addi	$s0,$s0,4
	
	bne	$t2,$t1,ciclo
	
		