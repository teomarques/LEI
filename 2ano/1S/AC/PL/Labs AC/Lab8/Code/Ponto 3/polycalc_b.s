		.data

		.text
		.globl	polycalc
polycalc:
	# Return a 0
	add $v0, $zero, $zero
	add $s0, $a0, $a1 # (x1 + x2)
	mul	$s0, 5		  # $t0 * 5 = Hi and Lo registers
	mflo $s0		  # copy Lo to $t0 -- (5(x1 + x2)
	# tratar do segundo parametro(x3 - 3*x4 * x5)
	mul $a3, 3 # 3 * x4
	mflo $s1 # 3 * x4
	# Ir buscaro último parametro (da tabela de parametros)
	lw $s2,16($sp)
	mul $s1, $s2 # 3*x4 * x5
	mflo $s1 # 3 * x4 * x5
	sub	$s1, $a2, $s1	#$s1 = a2 -s1	
	mul $s0, $s1
	mflo $v0
	jr	$ra
