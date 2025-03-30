.data

	str: .space 101
	char: .space 2
	
	
.text
.globl main

main:

	li $v0, 8
	la $a0, str
	li $a1, 101
	syscall # recolher string do terminal
	
	li $v0, 12
	syscall # recolher char do terminal e passar para a3
	move $a3, $v0
	
	jal codificaString
	la $a0, str
	li $v0, 4          # Syscall para imprimir string
    	syscall
    	
    	jal codificaString # Desencriptar a string

    	li $v0, 4          # Syscall para imprimir string desencriptada
	la $a0, str
    	syscall

    	li $v0, 10         # Encerrar programa
    	syscall
	
		
codificaString:
	
	ciclo:
		addi $a0, $a0, 1
		lb $t1, 0($a0)
		lb $t0, -1($a0)
		beq $t1, $zero, endFunction
		xor $t0, $t0, $a3
		sb $t0, -1($a0)
		j ciclo
		
	endFunction:
		jr $ra
