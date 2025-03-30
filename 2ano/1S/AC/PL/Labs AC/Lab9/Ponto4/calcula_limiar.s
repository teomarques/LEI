# O cabeçalho da função bin_img em C é
#
# void calcula_limiar(unsigned char *ptr, int w, int h);
	.data
	
	.text
	.globl calcula_limiar
	
calcula_limiar:

	li $v0, 0 # Média limiar
	lw $t0, 0($sp) # Ponteiro
	lw $t1, 4($sp) # Width
	lw $t2, 8($sp) # Height
	
	mul $t3, $t1, $t2 # Total pixels
	add $t4, $t3, $zero # Copiar total Pixels
	
	ciclo:
			beq $t3, $zero, end
			lb $t5, 0($t0)
			addi $t0, $t0, 1
			add $v0, $v0, $t5
			addi $t3, $t3, -1
			j ciclo
	end:
	div $v0, $t4
	mflo $v0
	jr $ra
	