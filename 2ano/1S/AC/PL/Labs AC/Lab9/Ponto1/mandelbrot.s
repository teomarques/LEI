	.data
	
	.text
	.globl	Mandelbrot

	
Mandelbrot:

	#Codigo da fun��o Mandelbrot aqui!
	
	# Em a0 est� z0
	# Em a1 est� o n�mero de itera��es
	move $v0, $a0
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	ciclo:
		beq $a1, $zero, endFunction
		move $a2, $v0
		jal calcula_quadrado
		add $v0, $v1, $a0
		addi $a1, $a1, -1		
		j ciclo
		
		
	endFunction:
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr	$ra

