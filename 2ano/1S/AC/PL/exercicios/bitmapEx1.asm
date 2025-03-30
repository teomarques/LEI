.text
.glbl main:
li	$t0, 0
li	$t1, 0x10010000
li	$t2, 120
addi	$t3, $t1, 5120
li	$t4, 0x00FFFF00

loop:
	add	$t5, $t1, $t0
	sw	$t4, 0($t5)
	addi	$t0, $t0, 4
	bne	$t0, $t2, loop
	# quando for igual, passa às linhas seguintes
	addi	$t1, $t1, 256
	beq	$t1, $t3, exit
	add	$t0, $0, $0
	j	loop

exit: