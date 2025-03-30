	.file	1 "lab8_4.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.abicalls
	.option	pic0
	.rdata
	.align	2
$LC0:
	.ascii	"Introduza a String:\000"
	.align	2
$LC1:
	.ascii	"Indique o caracter a procurar:\000"
	.align	2
$LC2:
	.ascii	"%c\000"
	.align	2
$LC3:
	.ascii	"O caracter '%c' aparece %d vezes na String!\012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.ent	main
	.type	main, @function
main:
	.frame	$fp,88,$31		# vars= 56, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-88
	sw	$31,84($sp)
	sw	$fp,80($sp)
	move	$fp,$sp
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	jal	puts
	nop

	addiu	$3,$fp,28
	lui	$2,%hi(stdin)
	lw	$2,%lo(stdin)($2)
	move	$4,$3
	li	$5,50			# 0x32
	move	$6,$2
	jal	fgets
	nop

	lui	$2,%hi($LC1)
	addiu	$4,$2,%lo($LC1)
	jal	puts
	nop

	lui	$2,%hi($LC2)
	addiu	$3,$2,%lo($LC2)
	addiu	$2,$fp,78
	move	$4,$3
	move	$5,$2
	jal	__isoc99_scanf
	nop

	lbu	$2,78($fp)
	addiu	$3,$fp,28
	move	$4,$3
	move	$5,$2
	jal	conta_char
	nop

	sw	$2,24($fp)
	lui	$2,%hi($LC3)
	addiu	$3,$2,%lo($LC3)
	lbu	$2,78($fp)
	move	$4,$3
	move	$5,$2
	lw	$6,24($fp)
	jal	printf
	nop

	move	$2,$0
	move	$sp,$fp
	lw	$31,84($sp)
	lw	$fp,80($sp)
	addiu	$sp,$sp,88
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 4.6.3-14) 4.6.3"
