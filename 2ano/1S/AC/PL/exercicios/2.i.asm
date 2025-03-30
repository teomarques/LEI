.data
tab:		.word 1, 2, 3, 4, 5, 6, 7
tab_size:	.word 7
message: 	.asciiz "The number of odd numbers in the table is: "

.text
main:
	lui	$a0, 0x0000			# initialize the count of numbers to 0
	ori	$a0, 0x0000
	la	$t0, tab			# loads address of the table in a1
	lw	$t1, tab_size			# loads a2 with the table size
	jal 	count_odd
	
	la 	$a0, message			# load message to display before syscall to print
	li	$v0, 4				# syscall for printing string
	syscall
	
	add	$a0, $zero, $a3			# move count of odd numbers
	li	$v0, 1				# syscall for printing integer
	syscall
	
	li	$v0, 10				# syscall for exit
	syscall

count_odd:
	lui	$a3, 0x0000			# initialize the count of numbers to 0
	ori	$a3, 0x0000

loop:
	lw 	$a1, 0($t0)			# loads first value of the table into a1
	andi 	$a2, $a1, 1			# checks if least signifficant bit is 1 (odd number)

	beq	$a2, $zero, skip_increment	# if even, ignore
	addi 	$a3, $a3, 1			# if odd, increment a0

skip_increment:
	addi	$t0, $t0, 4			# move to the next element of the table
	addi	$t1, $t1, -1			# decrement table size counter
	bne	$t1, $zero, loop		# continue to loop if there are still elements in the table

jr	$ra					# return to the calling function