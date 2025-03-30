	.file	"odd_numbers.c"
	.text
	.globl	odd
	.type	odd, @function
odd:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$31, %eax
	addl	%eax, %edx
	andl	$1, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	odd, .-odd
	.section	.rodata
.LC0:
	.string	"Number of args# = %d\n"
.LC1:
	.string	"%d\n"
.LC2:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movabsq	$7092454104028701775, %rax
	movq	%rax, -21(%rbp)
	movabsq	$16452483813633397, %rax
	movq	%rax, -16(%rbp)
	movl	-52(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -48(%rbp)
	jmp	.L4
.L5:
	movl	-48(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,8), %rdx
	movq	-64(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi@PLT
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-48(%rbp), %eax
	cltq
	movl	-44(%rbp), %edx
	movl	%edx, -40(%rbp,%rax,4)
	movl	-44(%rbp), %eax
	movl	%eax, %edi
	call	odd
	movl	-48(%rbp), %edx
	movslq	%edx, %rdx
	movl	%eax, -32(%rbp,%rdx,4)
	addl	$1, -48(%rbp)
.L4:
	movl	-48(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L5
	leaq	-21(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -48(%rbp)
	jmp	.L6
.L8:
	movl	-48(%rbp), %eax
	cltq
	movl	-32(%rbp,%rax,4), %eax
	cmpl	$1, %eax
	jne	.L7
	movl	-48(%rbp), %eax
	cltq
	movl	-40(%rbp,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L7:
	addl	$1, -48(%rbp)
.L6:
	movl	-52(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -48(%rbp)
	jl	.L8
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
