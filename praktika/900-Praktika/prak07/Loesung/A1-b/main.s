	.file	"main.cpp"
	.text
	.section	.text._ZN9RectangleC2Edd,"axG",@progbits,_ZN9RectangleC5Edd,comdat
	.align 2
	.weak	_ZN9RectangleC2Edd
	.type	_ZN9RectangleC2Edd, @function
_ZN9RectangleC2Edd:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movq	-8(%rbp), %rax
	movsd	-16(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movq	-8(%rbp), %rax
	movsd	-24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN9RectangleC2Edd, .-_ZN9RectangleC2Edd
	.weak	_ZN9RectangleC1Edd
	.set	_ZN9RectangleC1Edd,_ZN9RectangleC2Edd
	.section	.text._ZNK9Rectangle4getAEv,"axG",@progbits,_ZNK9Rectangle4getAEv,comdat
	.align 2
	.weak	_ZNK9Rectangle4getAEv
	.type	_ZNK9Rectangle4getAEv, @function
_ZNK9Rectangle4getAEv:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_ZNK9Rectangle4getAEv, .-_ZNK9Rectangle4getAEv
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movsd	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rdx
	leaq	-32(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rdi
	call	_ZN9RectangleC1Edd
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9Rectangle4getAEv
	movq	%xmm0, %rax
	movq	%rax, -48(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK9Rectangle7getAreaEv@PLT
	movq	%xmm0, %rax
	movq	%rax, -40(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1075052544
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
