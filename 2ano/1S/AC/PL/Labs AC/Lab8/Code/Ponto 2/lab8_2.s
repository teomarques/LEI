	.file	1 "lab8_2.c"
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
	.frame	$fp,56,$31		# vars= 24, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$fp,48($sp)
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

	lw	$4,32($fp)
	lw	$5,36($fp)
	lw	$3,40($fp)
	lw	$2,44($fp)
	move	$6,$3
	move	$7,$2
	jal	max
	nop

	sw	$2,24($fp)
	lw	$4,32($fp)
	lw	$5,36($fp)
	lw	$3,40($fp)
	lw	$2,44($fp)
	move	$6,$3
	move	$7,$2
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
	lw	$31,52($sp)
	lw	$fp,48($sp)
	addiu	$sp,$sp,56
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 4.6.3-14) 4.6.3"
