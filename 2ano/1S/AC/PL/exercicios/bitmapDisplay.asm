    .data
amarelo: 
    .word 0x00FFFF00  # First pixel, yellow (24-bit RGB: FF FF 00)

    .text
    .globl main

main:
    # Assuming framebuffer address is in $a0 and the first pixel should be yellow
    la   $t0, amarelo  # Load address of the bitmap (yellow pixel)
    lw   $t1, 0($t0)  # Load first pixel color (0xFFFF00)

    li   $t2, 0x10010000 # framebuffer adress
    sw   $t1, 0($t2)     # Store the yellow pixel to the framebuffer
