.data

.text
    li $s0, 0xFFFF0010    # Address of the left display
    li $s1, 0xFFFF0011    # Address of the right display
    addi $t0, $zero, 0x01          # Initialize $t0 to 0x01 (first segment)
    addi $t1, $zero, 7             # Number of segments in a 7-segment display (7)

ciclo:
    sb   $t0, 0($s0)               # Write $t0 (which has 1 bit set) to the right display
    sll  $t0, $t0, 1               # Shift left to move to the next segment
    addi $t1, $t1, -1              # Decrease segment counter
    bne $t1, $zero, ciclo                # Repeat until all segments are lit

    # Reset the loop for another display or another cycle
    addi $t0, $zero, 0x01          # Reset $t0 to 0x01 to start again
    addi $t1, $zero, 7             # Reset segment counter to 7
    j    ciclo                     # Jump to ciclo and repeat indefinitely

exit:
    li   $v0, 10                   # Exit syscall (for MIPS environments)
    syscall
