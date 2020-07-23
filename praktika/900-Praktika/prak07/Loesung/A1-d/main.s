	.file	"main.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	movq	.LC0(%rip), %rax
	movq	%rax, (%rsp)
	movq	.LC1(%rip), %rax
	movq	%rax, 8(%rsp)
	movq	%rsp, %rdi
	call	_ZNK9Rectangle7getAreaEv@PLT
	movq	24(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L4
	movl	$0, %eax
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1073741824
	.align 8
.LC1:
	.long	0
	.long	1075052544
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
