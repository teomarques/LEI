.data

	tab: .word 1, 2, 3, 4, 5, 6, 7, 9, 11
	
.text
.globl main

main:

	la $a0, tab
	li $a1, 9
	jal oddnumber
	
endProgram:
	li $t0, 9
	la $a1, tab
	li $v0, 1
	cicloFinal:
		beq $t0, $zero, end
		lw $a0, 0($a1)
		addi $a1, $a1, 4
		addi $t0, $t0, -1
		syscall
		j cicloFinal
	end:
	li $v0, 10
	syscall
	
oddnumber:

	li $t0, 0x00000001 # Mascara para verificar se é impar
	li $t3, 0xFFFFFFFE
	li $t1, 0 # Resultado da Máscara
	ciclo:
		beq $a1, $zero, endFunction
		addi $a1, $a1, -1
		lw $t2, 0($a0) # carrega o numero da tab
		and $t1, $t0, $t2
		beq $t1, $t0, mudaImpares
		addi $a0, $a0, 4
		j ciclo
		
	mudaImpares:
					   #   F  F     F   F    F  F     F   E
		and $t2, $t2, $t3 	   # 11111111 11111111 11111111 11111110
		sw $t2, 0($a0)
		addi $a0, $a0, 4
		j ciclo
		
	endFunction:
	
		jr $ra