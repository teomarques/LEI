 # O cabeçalho da função bin_img em C é
#
# void bin_img(unsigned char *ptr, int w, int h);

	.data
	
	.text
	.globl	bin_img
	
bin_img:
	
	
# Codigo da função aqui
	addi $sp, $sp, -16
	sw $a0, 0($sp)
	sw $a1, 4($sp)
	sw $a2, 8($sp)
	sw $ra, 12($sp)
	jal calcula_limiar
	mul $t0, $a1, $a2 			# Calcula w * h
	ciclo:
		beq $t0, $zero, fim
		lbu $t1, 0($a0)
		blt $t1, $v0, replaceZero
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
	lw $ra, 12($sp)
	addi $sp, $sp, 16
		jr	$ra

