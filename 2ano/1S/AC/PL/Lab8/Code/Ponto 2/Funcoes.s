	.data
	
	.text
	.globl	max
	.globl	min
	
max:
	add $v0, $zero, $a0
	bge $a1, $v0, setmax1
	bge $a2, $v0, setmax2
	bge $a3, $v0, setmax3
	jr	$ra

setmax1:
	add $v0, $zero, $a1
	j max
	
setmax2:
	add $v0, &zero, $a2
	j max
	
setmax3:
	add $v0, $zero, $a3

min:
	add $v0, $zero, $a0
	blt $a1, $v0, setmax1
	blt $a2, $v0, setmax2
	blt $a3, $v0, setmax3
	jr	$ra

setmax1:
	add $v0, $zero, $a1
	j max
	
setmax2:
	add $v0, &zero, $a2
	j max
	
setmax3:
	add $v0, $zero, $a3

	jr	$ra
