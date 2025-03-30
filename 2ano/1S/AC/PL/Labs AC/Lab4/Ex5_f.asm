.data

	num: .word 0x0000FFFF # 00000000 00000000 11111111 10101010
	
.text	
.globl main

main:
	la $t1, num
 	lw $a0, 0($t1)
 	jal contaBits

end:

	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 10
	syscall
 	
contaBits:

	li $t0, 0x00000001 # Máscara para Verificar Bit a Bit
	li $t1, 32 # Decremento
	li $v0, 0 # Counter 1s
	li $t3, 0x00000000 # Resultado da Máscara
	
	ciclo:
		beq $t1, $zero, endFunction
		addi $t1, $t1, -1
		and $t3, $t0, $a0
		beq $t3, $t0, aumentaCounter
		sll $t0, $t0, 1
		j ciclo
		
	aumentaCounter:
		addi $v0, $v0, 1
		sll $t0, $t0, 1
		j ciclo
		
	endFunction:
	
		jr $ra