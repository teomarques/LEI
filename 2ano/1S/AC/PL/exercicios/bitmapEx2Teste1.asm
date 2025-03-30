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

main2:
	li	$t0, 12144
	li	$t7, 0x00FF00FF		# Pink color (0x00 FF 00 FF)
	li	$t8, 12177
	li	$t9, 20112
square:
	add	$t6, $t1, $t0
	sw	$t7, 0($t4)
	addi	$t0, $t0, 4
	
	bne	$t4, $t8, square
	beq	$t0, $t9, exit
	addi	$t8, $t8, 224
	addi	$t0, $t0, 4
	
exit: