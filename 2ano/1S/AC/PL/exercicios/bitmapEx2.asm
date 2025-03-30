.data
    .globl main

.text
main:
    li      $t0, 0                # Counter to keep track of pixel position (offset)
    li      $t1, 0x10010000        # Base address of the framebuffer
    li      $t3, 0x0000FFFF        # Blue color (0x00 00 FF FF) - 32-bit pixel
    li      $t5, 131072            # 256 * 128 * 4 = 131072 bytes (size of the entire screen)

# Loop to paint the entire screen blue
loop:
    add     $t4, $t1, $t0          # Calculate address: base + offset
    sw      $t3, 0($t4)            # Store the blue color at calculated address
    addi    $t0, $t0, 4            # Move to the next pixel (4 bytes per pixel)
    
    # Exit condition after all pixels are painted
    beq     $t0, $t5, main2        # If $t0 reaches the total screen size, exit loop
    j       loop                   # Otherwise, repeat

# Now, draw a square in the middle of the screen
main2:
    li      $t3, 0x00FF00FF        # Pink color (0x00FF00FF)

    # Calculate starting point for the square in the middle of the screen
    # 256 pixels wide and 128 pixels high, so middle row is 48, and middle column is 112
    li      $t6, 48                # Start drawing at row 48
    li      $t7, 112               # Start drawing at column 112

    # Draw a 32x32 square in the middle of the screen
    li      $s0, 32                # Square width and height (32x32)

draw_square:
    # Outer loop: for rows
    li      $t8,48                 # Row offset (starting at row 48)
row_loop:
    li      $t0, 0                 # Column offset for each row
col_loop:
    # Calculate the memory address for the current pixel
    mul     $t2, $t8, 256          # Row offset: row * screen width (256 pixels per row)
    add     $t2, $t2, $t7          # Add column offset
    add     $t2, $t2, $t0          # Add column iteration offset (for square width)
    add     $t4, $t1, $t2          # Add base address of the framebuffer
    
    # Draw the pink pixel at this address
    sw      $t3, 0($t4)
    
    # Move to the next column
    addi    $t0, $t0, 4            # Move to the next pixel in the square
    
    # Loop for the width of the square (16 pixels)
    blt     $t0, $s0, col_loop

    # Move to the next row
    addi    $t8, $t8, 4            # Move to the next row
    
    # Loop for the height of the square (16 pixels)
    blt     $t8, $s0, row_loop

exit:
    li      $v0, 10                # Syscall to exit the program
    syscall
