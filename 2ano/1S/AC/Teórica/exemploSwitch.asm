.data

main:
bne		$s5, $0, L1		# branch k != 0
add		$s0, $s3, $s4		# k == 0 so f = i + j
j		Exit
L1:
addi		$t0, $s5, -1		# $t0 = k - 1
bne		$t0, $0, Exit		# branch k != 1
add		$s0, $s1, $s2		# k == 1 so f = g + h
j		Exit


Exit:


#Exemplo para o seguinte switch:
#	switch(k) {
#		case 0: f = i + j; break;		k = 0
#		case 1: f = g + h; break;		k = 1
