# O cabeçalho da função bin_img em C é
#
# void bin_img(unsigned char *ptr, int w, int h, unsigned char limiar);

	.data
	
	.text
	.globl	bin_img
	
bin_img:
	
	
# Codigo da função aqui
	mul $t0, $a1, $a2 			# Calcula w * h
	ciclo:
		beq $t0, $zero, fim
		lbu $t1, 0($a0)
		blt $t1, $a3, replaceZero
		li $t2, 255
		sb $t2, 0($a0)
		addi $a0, $a0, 1
		addi $t0, $t0, -1
		j ciclo
		
	replaceZero:
		sb $zero, 0($a0)
		addi $a0, $a0, 1
		addi $t0, $t0, -1
		j ciclo
	
fim:
		jr	$ra

