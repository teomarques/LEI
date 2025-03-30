	.file	"count.c"
	.text
	.globl	count
	.bss
	.align 4
	.type	count, @object
	.size	count, 4
count:
	.zero	4
	.globl	exited_threads
	.align 4
	.type	exited_threads, @object
	.size	exited_threads, 4
exited_threads:
	.zero	4
	.globl	count_mutex
	.align 32
	.type	count_mutex, @object
	.size	count_mutex, 40
count_mutex:
	.zero	40
	.globl	count_threshold_cv
	.align 32
	.type	count_threshold_cv, @object
	.size	count_threshold_cv, 48
count_threshold_cv:
	.zero	48
	.section	.rodata
	.align 8
.LC0:
	.string	"Thread %ld started incrementing counter - will do it %d times\n"
.LC1:
	.string	"Thread %ld: count = %d\n"
.LC2:
	.string	"Thread %ld leaving!\n"
	.text
	.globl	increment_count
	.type	increment_count, @function
increment_count:
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
	movq	%rax, -8(%rbp)
	call	rand@PLT
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$30, %eax
	addl	%eax, %edx
	andl	$3, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	addl	$2, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -16(%rbp)
	jmp	.L2
.L3:
	leaq	count_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_lock@PLT
	movl	count(%rip), %eax
	addl	$1, %eax
	movl	%eax, count(%rip)
	movl	count(%rip), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	count_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	movl	$1, %edi
	call	sleep@PLT
	addl	$1, -16(%rbp)
.L2:
	movl	-16(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L3
	leaq	count_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_lock@PLT
	movl	exited_threads(%rip), %eax
	addl	$1, %eax
	movl	%eax, exited_threads(%rip)
	leaq	count_threshold_cv(%rip), %rax
	movq	%rax, %rdi
	call	pthread_cond_signal@PLT
	leaq	count_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE6:
	.size	increment_count, .-increment_count
	.section	.rodata
	.align 8
.LC3:
	.string	"Thread %ld started watching threads\n"
	.text
	.globl	watch_threads
	.type	watch_threads, @function
watch_threads:
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
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	count_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_lock@PLT
	jmp	.L5
.L6:
	leaq	count_mutex(%rip), %rax
	movq	%rax, %rsi
	leaq	count_threshold_cv(%rip), %rax
	movq	%rax, %rdi
	call	pthread_cond_wait@PLT
.L5:
	movl	exited_threads(%rip), %eax
	cmpl	$4, %eax
	jle	.L6
	leaq	count_mutex(%rip), %rax
	movq	%rax, %rdi
	call	pthread_mutex_unlock@PLT
	movl	$0, %edi
	call	pthread_exit@PLT
	.cfi_endproc
.LFE7:
	.size	watch_threads, .-watch_threads
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
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	leaq	-112(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rdx, %rcx
	leaq	watch_threads(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	movl	$0, -116(%rbp)
	jmp	.L8
.L9:
	movl	-116(%rbp), %eax
	movslq	%eax, %rdx
	movl	-116(%rbp), %eax
	cltq
	movq	%rdx, -112(%rbp,%rax,8)
	leaq	-112(%rbp), %rax
	movl	-116(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rax, %rdx
	leaq	-64(%rbp), %rax
	movl	-116(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$3, %rcx
	addq	%rcx, %rax
	movq	%rdx, %rcx
	leaq	increment_count(%rip), %rdx
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_create@PLT
	addl	$1, -116(%rbp)
.L8:
	cmpl	$4, -116(%rbp)
	jle	.L9
	movl	$0, -116(%rbp)
	jmp	.L10
.L11:
	movl	-116(%rbp), %eax
	cltq
	movq	-64(%rbp,%rax,8), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	pthread_join@PLT
	addl	$1, -116(%rbp)
.L10:
	cmpl	$5, -116(%rbp)
	jle	.L11
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
