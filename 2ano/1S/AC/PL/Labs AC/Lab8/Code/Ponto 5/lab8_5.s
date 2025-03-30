	.file	1 "lab8_5.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.abicalls
	.option	pic0
	.rdata
	.align	2
$LC0:
	.ascii	"Introduza o primeiro valor:\000"
	.align	2
$LC1:
	.ascii	"%d\000"
	.align	2
$LC2:
	.ascii	"Introduza o segundo valor:\000"
	.align	2
$LC3:
	.ascii	"Introduza o terceiro valor:\000"
	.align	2
$LC4:
	.ascii	"Introduza o quarto valor:\000"
	.align	2
$LC5:
	.ascii	"O valor maximo: %d\012\000"
	.align	2
$LC6:
	.ascii	"O valor minimo: %d\012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.ent	main
	.type	main, @function
main:
	.frame	$fp,72,$31		# vars= 40, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-72
	sw	$31,68($sp)
	sw	$fp,64($sp)
	move	$fp,$sp
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	jal	puts
	nop

	lui	$2,%hi($LC1)
	addiu	$3,$2,%lo($LC1)
	addiu	$2,$fp,32
	move	$4,$3
	move	$5,$2
	jal	__isoc99_scanf
	nop

	lui	$2,%hi($LC2)
	addiu	$4,$2,%lo($LC2)
	jal	puts
	nop

	lui	$2,%hi($LC1)
	addiu	$3,$2,%lo($LC1)
	addiu	$2,$fp,36
	move	$4,$3
	move	$5,$2
	jal	__isoc99_scanf
	nop

	lui	$2,%hi($LC3)
	addiu	$4,$2,%lo($LC3)
	jal	puts
	nop

	lui	$2,%hi($LC1)
	addiu	$3,$2,%lo($LC1)
	addiu	$2,$fp,40
	move	$4,$3
	move	$5,$2
	jal	__isoc99_scanf
	nop

	lui	$2,%hi($LC4)
	addiu	$4,$2,%lo($LC4)
	jal	puts
	nop

	lui	$2,%hi($LC1)
	addiu	$3,$2,%lo($LC1)
	addiu	$2,$fp,44
	move	$4,$3
	move	$5,$2
	jal	__isoc99_scanf
	nop

	lw	$2,32($fp)
	sw	$2,48($fp)
	lw	$2,36($fp)
	sw	$2,52($fp)
	lw	$2,40($fp)
	sw	$2,56($fp)
	lw	$2,44($fp)
	sw	$2,60($fp)
	addiu	$2,$fp,48
	move	$4,$2
	li	$5,4			# 0x4
	jal	max
	nop

	sw	$2,24($fp)
	addiu	$2,$fp,48
	move	$4,$2
	li	$5,4			# 0x4
	jal	min
	nop

	sw	$2,28($fp)
	lui	$2,%hi($LC5)
	addiu	$2,$2,%lo($LC5)
	move	$4,$2
	lw	$5,24($fp)
	jal	printf
	nop

	lui	$2,%hi($LC6)
	addiu	$2,$2,%lo($LC6)
	move	$4,$2
	lw	$5,28($fp)
	jal	printf
	nop

	move	$2,$0
	move	$sp,$fp
	lw	$31,68($sp)
	lw	$fp,64($sp)
	addiu	$sp,$sp,72
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 4.6.3-14) 4.6.3"
