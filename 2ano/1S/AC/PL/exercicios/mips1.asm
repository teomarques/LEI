.data
tab:	.word 1, 2, 3, 4


	.text
	.global main
main:
	li $v0, 5		# in sytem call, the value 5 stands for read int, and reads input from user
	syscall

	la $t0, tab		# load address with the first value in the table, works like a pointer
	lw $t1, 4($t0)		# loads t1 with second value in table (t0)
	add $a0, $v0, $t1

	addi $a0, $v0, 50
	li $v0, 1
	syscall