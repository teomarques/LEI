# exercise 1 of pl4

.data
str: .asciiz "Bom Dia!"
comp: .word 0

.text
.globl main

main:
la $a0, str
jal count
la $t0, comp
sw $v0, 0($t0)
move $a0, $v0
li $v0, 1
syscall
li $v0, 10
syscall

count:
add $v0, $s0, $0
	loop:
	lb $t0, 0($a0)
	beq $t0, $0, exit
	addi $v0, $v0, 1
	addi $a0, $a0, 1
	j	loop
exit:
jr $ra