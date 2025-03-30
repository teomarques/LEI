.data

	tab: .word 1, 2, 3, 4, 5, 6, 7, 9, 11
	
.text
.globl main

main:

	la $a0, tab
	li $a1, 9
	jal oddnumber
	
endProgram:

	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 10
	syscall
	
oddnumber:

	li $t0, 0x00000001 # Mascara para verificar se é impar
	li $t1, 0 # Resultado da Máscara
	li $v0, 0 # Conta Impares
	ciclo:
		beq $a1, $zero, endFunction
		addi $a1, $a1, -1
		lw $t2, 0($a0) # carrega o numero da tab
		and $t1, $t0, $t2
		addi $a0, $a0, 4
		beq $t1, $t0, somaImpares
		j ciclo
		
	somaImpares:
	
		addi $v0, $v0, 1
		j ciclo
		
	endFunction:
	
		jr $ra
		
		
	