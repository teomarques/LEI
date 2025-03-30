	.data

	.text
	.globl	inverte_tabela
inverte_tabela:
	mul $t2, $a1, 4
	sub $t2, $t2, 4  # Calcula o tamanho total de elementos para avançar
	add $t1, $a0, $t2  # Recolher o último elemento
	
	div $a1, 2
	
	ciclo_inverter:
		beq $a1, $zero, end_inversao
		
		lw $t3, 0($a0)  
		lw $t4, 0($t1)  
		sw $t4, 0($a0)  
		sw $t3, 0($t1)
	
		addi $a0, $a0, 4  
		addi $t1, $t1, -4 
		addi $a1, $a1, -1 
		
		j ciclo_inverter

	end_inversao:
		jr $ra
