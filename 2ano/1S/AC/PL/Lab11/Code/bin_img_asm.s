# O cabeçalho da função bin_img_asm em C é
#
# void bin_img_asm(unsigned char *ptr, int w, int h);

	.data
	
	.text
	.globl	bin_img_asm
	
bin_img_asm:
	
	mult $a1, $a2
	mflo $t0            # total de pixels

	addi $t1, $0, 0     # soma todos os pixels

	loop:

	    lb $t2, 0($a0)
	    addi $a0, $a0, 1
	    add $t1, $t1, $t2
	    bne $t1, $t0, loop

	addi $a0, $a0, $t0      # volta o ponteiro ao inicio da imagem
	div $t1, $t0
	mflo $t1

	compara_cores:
	    lb $t0, 0($a0)
	    bge $t0, $t1, carrega_branco

	    j compara_cores

	carrega_branco:
	
fim:
		jr	$ra

