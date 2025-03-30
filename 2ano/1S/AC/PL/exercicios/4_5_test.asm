.data
    message: .asciiz "The parity result is: "

.text
main:
    # Initialize $v0 with a value (for demonstration)
    lui $v0, 0x0100
    ori $v0, $v0, 0x0011

    jal paridade               # Call the parity function to process the value in $v0

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
    li $v0, 10                 # Exit syscall (in case of early exit)
    syscall

# Function to compute the parity of $v0
paridade:
    addi $a2, $zero, 0         # Initialize $a2 to 0 to count parity bits
loop:
    andi $a1, $v0, 0x0001      # Extract the least significant bit of $v0
    beq $a1, $zero, skip       # If the bit is 0, skip incrementing $a2
    addi $a2, $a2, 1           # Increment parity count if bit is 1
skip:
    srl $v0, $v0, 1            # Shift the value in $v0 to the right by 1 bit
    bne $v0, $zero, loop       # Continue looping if $v0 is not zero
    jr $ra                     # Return to the calling function
