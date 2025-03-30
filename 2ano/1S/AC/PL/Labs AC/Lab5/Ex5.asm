.data

	tab: .word 10,24,32,40,64,128
	
.text

.globl main
main:

	la $a0, tab
	jal somatorio
	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 10
	syscall
	
somatorio:

	li $t0, 6 # LIMITE
	li $t1, 0 # Counter
	li $t2, 0x00000001
	li $v0, 0 # Resultado Final
	ciclo:
	
		beq $t1, $t0, endSom
		lw $t3, 0($a0) # Carrega valor da tab
		addi $a0, $a0, 4
		li $t4, 0
		ciclo2:
			beq $t4, $t1, endCiclo2
			srl $t3, $t3, 1
			addi $t4, $t4, 1
			j ciclo2
			
		endCiclo2:
		addi $t1, $t1, 1
		add $v0, $v0, $t3
		j ciclo
	endSom:
		jr $ra
