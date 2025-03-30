.data

	str: .asciiz "Apenas Um TesteZ"

.text
.globl main

main:

	la $a0, str
	li $v0, 4
	syscall
	jal mudaLetras
	
end:
	la $a0, str
	li $v0, 4
	syscall
	li $v0, 10
	syscall
	
mudaLetras:

	li $t1, 0x7A # limite superior minusculas - z
	li $t2, 0x61 # limite inferior minusculas - a
	li $t3, 0x41 # Letra 'A'
	ciclo:	
		lb $t0, 0($a0)
		addi $a0, $a0, 1
		beq $t0, $zero, endFunction
		bgt $t0, $t1, ciclo
		bge $t0, $t2, mudaChar
		j ciclo
		
	mudaChar:
	
		sub $t4, $t0, $t2
		add $t4, $t4, $t3
		sb $t4, -1($a0)
		j ciclo
		
	endFunction:
	
		jr $ra
		