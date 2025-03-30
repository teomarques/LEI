	.data
	.text

	.globl my_atoi

my_atoi:

	# a0 -> char *str, que é "23 -87 67"
	# a1 -> int *tab

	li $v0, 0
	loadChar:
		lb $t0, 0($a0)			# carrega primeiro caractere da tabela
		beq $t0, $zero, end
		lb $t1, 1($a0)			# carrega segundo caractere da tabela
		j verifica
		j nextChar
		j loadChar

	verifica:
		bne $t0, 0x2D, nextChar
                addi $v0, $v0, 1
                j incrementaNegativo

	incrementaNegativo:
                addiu $a1, $a1, 1
                addiu $a0, $a0, 1
		j loadChar

	nextChar:
		sub $t0, $t0, 0x30		# busca o valor numerico
		bne $t1, 0x20, decimal
		sw $t0, 0($a1)
		j incrementa

	decimal:
		mul $t0, $t0, 10
		sub $t1, $t1, 30
		add $t0, $t0, $t1
		sw $t0, 0($a1)
		j incrementa

	incrementa:
		addiu $a1, $a1, 1
		addiu $a0, $a0, 1

	end:

	jr	$ra

