.data 
message: .asciiz "The parity result is: "

.text 
# addi $v0, $zero, 0
# is the same as:
lui $v0, 0x0100
ori $v0, $v0, 0x0011
lui $a2, 0x0000
ori $a2, 0x0000
jal paridade

# Print the message before displaying the value of $a2
la $a0, message            # Load address of the message string
li $v0, 4                  # Syscall for printing a string
syscall

# Print the result stored in $a2
move $a0, $a2              # Move the result to $a0 for printing
li $v0, 1                  # Syscall to print integer
syscall

li $v0, 10                 # Exit syscall
syscall

exit:
li $v0, 10
syscall

paridade:
addi $a2, $a2, 1
loop:
	add $a0, $zero, $v0 #move value from v0 to a0
	andi $a1, $a0, 0x0001 #extract the last bit
	srl $a0, $a0, 1	#shift value in a1 by 1 bite (our variable)
	beq $a1, 0x0001, paridade #if bit extracted is 0, go back to paridade
	addi $a2, $a2, -1
	bne $a0, $zero, loop
jr $ra
