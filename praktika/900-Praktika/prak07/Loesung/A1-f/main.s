	.file	"main.cpp"
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	subq	$56, %rsp
	.cfi_def_cfa_offset 64
	movapd	.LC0(%rip), %xmm0
	leaq	16(%rsp), %rdi
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	movaps	%xmm0, 16(%rsp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, 8(%rsp)
	call	_Z13getRectangleBRK9Rectangle@PLT
	movsd	%xmm0, 8(%rsp)
	movq	40(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L5
	xorl	%eax, %eax
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1073741824
	.long	0
	.long	1075052544
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
