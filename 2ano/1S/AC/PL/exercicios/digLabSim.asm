.data
.text


ciclo2:
li	$t0, 0xFFFF0010
li	$t1, 0x01
li	$t2, 8

ciclo:
sb	$t1, 0($t0)
sll	$t1, $t1, 1			#faz os bits rodarem à esquerda de um a um
addi	$t2, $t2, -1
bne	$t2, $zero, ciclo
j	ciclo2
