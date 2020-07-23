	.file	"main.cpp"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB30:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	leaq	_ZZ4mainE6table2(%rip), %r14
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	_ZZ4mainE6table3(%rip), %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	.LC0(%rip), %rbp
	movl	$8, %ebx
	xorl	%r12d, %r12d
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leaq	16(%rsp), %rcx
	movabsq	$8589934593, %rax
	leaq	28(%rsp), %r15
	movq	%rax, 16(%rsp)
	movl	$3, 24(%rsp)
	movq	%rax, 28(%rsp)
	movl	$3, 36(%rsp)
.L2:
	movl	(%rcx,%r12), %edx
	movq	%rbp, %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	movq	%rcx, 8(%rsp)
	call	__printf_chk@PLT
	movl	(%r15,%rbx), %edx
	movq	%rbp, %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movl	(%r14,%r12), %eax
	movq	%rbp, %rsi
	movl	$1, %edi
	addq	$4, %r12
	leal	2(%rax), %edx
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movl	0(%r13,%rbx), %edx
	xorl	%eax, %eax
	movq	%rbp, %rsi
	movl	$1, %edi
	subq	$4, %rbx
	call	__printf_chk@PLT
	cmpq	$-4, %rbx
	movq	8(%rsp), %rcx
	jne	.L2
	xorl	%eax, %eax
	movq	40(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L7
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L7:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE30:
	.size	main, .-main
	.section	.rodata
	.align 8
	.type	_ZZ4mainE6table2, @object
	.size	_ZZ4mainE6table2, 12
_ZZ4mainE6table2:
	.long	1
	.long	2
	.long	3
	.set	_ZZ4mainE6table3,_ZZ4mainE6table2
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
