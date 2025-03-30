	.file	1 "lab8_3.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.abicalls
	.option	pic0
	.rdata
	.align	2
$LC0:
	.ascii	"Resultado Calculado na Funcao Assembly: %d\012\000"
	.align	2
$LC1:
	.ascii	"Resultado Calculado em C: %d\012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.ent	main
	.type	main, @function
main:
	.frame	$fp,64,$31		# vars= 24, regs= 2/0, args= 24, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-64
	sw	$31,60($sp)
	sw	$fp,56($sp)
	move	$fp,$sp
	li	$2,7			# 0x7
	sw	$2,36($fp)
	li	$2,8			# 0x8
	sw	$2,40($fp)
	li	$2,10			# 0xa
	sw	$2,44($fp)
	li	$2,2			# 0x2
	sw	$2,48($fp)
	li	$2,1			# 0x1
	sw	$2,52($fp)
	lw	$4,36($fp)
	lw	$5,40($fp)
	lw	$3,44($fp)
	lw	$2,48($fp)
	lw	$6,52($fp)
	sw	$6,16($sp)
	move	$6,$3
	move	$7,$2
	jal	polycalc
	nop

	sw	$2,32($fp)
	lui	$2,%hi($LC0)
	addiu	$2,$2,%lo($LC0)
	move	$4,$2
	lw	$5,32($fp)
	jal	printf
	nop

	lui	$2,%hi($LC1)
	addiu	$4,$2,%lo($LC1)
	lw	$3,36($fp)
	lw	$2,40($fp)
	addu	$3,$3,$2
	move	$2,$3
	sll	$2,$2,2
	addu	$6,$2,$3
	lw	$5,44($fp)
	lw	$3,48($fp)
	move	$2,$3
	sll	$2,$2,1
	addu	$2,$2,$3
	subu	$2,$0,$2
	lw	$3,52($fp)
	mult	$2,$3
	mflo	$2
	addu	$2,$5,$2
	nop
	mult	$6,$2
	mflo	$2
	move	$5,$2
	jal	printf
	nop

	move	$sp,$fp
	lw	$31,60($sp)
	lw	$fp,56($sp)
	addiu	$sp,$sp,64
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Debian 4.6.3-14) 4.6.3"
