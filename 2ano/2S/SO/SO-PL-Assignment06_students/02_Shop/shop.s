	.file	"shop.c"
	.text
	.globl	sales
	.bss
	.align 4
	.type	sales, @object
	.size	sales, 4
sales:
	.zero	4
	.globl	money
	.align 4
	.type	money, @object
	.size	money, 4
money:
	.zero	4
	.globl	money_mutex
	.align 32
	.type	money_mutex, @object
	.size	money_mutex, 40
money_mutex:
	.zero	40
	.globl	money_amount_cv
	.align 32
	.type	money_amount_cv, @object
	.size	money_amount_cv, 48
money_amount_cv:
	.zero	48
	.section	.rodata
	.align 8
.LC0:
	.string	"Starting employee(): thread %d\n"
	.align 8
.LC1:
	.string	"Employee %d: sale %d, money in safe = %d\n"
	.text
	.globl	employee
	.type	employee, @function
employee:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L5:
	leaq	money_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_lock@PLT
	movl	sales(%rip), %eax
	cmpl	$29, %eax
	jg	.L2
	movl	sales(%rip), %eax
	addl	$1, %eax
	movl	%eax, sales(%rip)
	movl	money(%rip), %eax
	addl	$10, %eax
	movl	%eax, money(%rip)
	leaq	money_amount_cv(%rip), %rax
	movq	%rax, %rdi
	call	pthread_cond_signal@PLT
	movl	money(%rip), %ecx
	movl	sales(%rip), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L6
.L2:
	leaq	money_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	nop
	movl	$0, %edi
	call	pthread_exit@PLT
.L6:
	leaq	money_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	jmp	.L5
	.cfi_endproc
.LFE6:
	.size	employee, .-employee
	.section	.rodata
	.align 8
.LC2:
	.string	"Starting foreman(): thread %d\n"
	.align 8
.LC3:
	.string	"Foreman %d: money in safe = %d\n"
	.text
	.globl	foreman
	.type	foreman, @function
foreman:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L13:
	leaq	money_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_lock@PLT
	jmp	.L8
.L10:
	leaq	money_mutex(%rip), %rax
	movq	%rax, %rsi
	leaq	money_amount_cv(%rip), %rax
	movq	%rax, %rdi
	call	pthread_cond_wait@PLT
.L8:
	movl	money(%rip), %eax
	cmpl	$49, %eax
	jg	.L9
	movl	sales(%rip), %eax
	cmpl	$29, %eax
	jle	.L10
.L9:
	movl	sales(%rip), %eax
	cmpl	$29, %eax
	jle	.L11
	leaq	money_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	nop
	movl	$0, %edi
	call	pthread_exit@PLT
.L11:
	movl	money(%rip), %eax
	subl	$50, %eax
	movl	%eax, money(%rip)
	movl	money(%rip), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	money_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	jmp	.L13
	.cfi_endproc
.LFE7:
	.size	foreman, .-foreman
	.section	.rodata
	.align 8
.LC4:
	.string	"Main(): Waited and joined with %d threads. Final money in safe = %d. Done!\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$144, %rsp
	movl	%edi, -132(%rbp)
	movq	%rsi, -144(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -116(%rbp)
	jmp	.L15
.L18:
	movl	-116(%rbp), %eax
	cltq
	movl	-116(%rbp), %edx
	movl	%edx, -112(%rbp,%rax,4)
	cmpl	$0, -116(%rbp)
	jne	.L16
	leaq	-112(%rbp), %rax
	movl	-116(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	leaq	-80(%rbp), %rax
	movl	-116(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$3, %rcx
	addq	%rcx, %rax
	movq	%rdx, %rcx
	leaq	foreman(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	jmp	.L17
.L16:
	leaq	-112(%rbp), %rax
	movl	-116(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	leaq	-80(%rbp), %rax
	movl	-116(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$3, %rcx
	addq	%rcx, %rax
	movq	%rdx, %rcx
	leaq	employee(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
.L17:
	addl	$1, -116(%rbp)
.L15:
	cmpl	$7, -116(%rbp)
	jle	.L18
	movl	$0, -116(%rbp)
	jmp	.L19
.L20:
	movl	-116(%rbp), %eax
	cltq
	movq	-80(%rbp,%rax,8), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	addl	$1, -116(%rbp)
.L19:
	cmpl	$7, -116(%rbp)
	jle	.L20
	movl	money(%rip), %eax
	movl	%eax, %edx
	movl	$8, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE8:
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
