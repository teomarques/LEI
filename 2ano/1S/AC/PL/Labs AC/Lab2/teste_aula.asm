.text

.globl main

main:
	
	li $t0, 0x00FF00FF
	li $t1, 0x10010000
	sw $t0, 0($t1)
	
	
	# Para alcançar um pixel (i,j), temos de somar ao endereço base o valor i*256 + j * 4