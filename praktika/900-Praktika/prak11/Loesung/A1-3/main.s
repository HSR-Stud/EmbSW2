	.file	"main.cpp"
	.text
	.globl	const1
	.section	.rodata
	.align 8
	.type	const1, @object
	.size	const1, 8
const1:
	.long	1558557732
	.long	1081803658
	.globl	const2
	.align 8
	.type	const2, @object
	.size	const2, 8
const2:
	.long	2946691162
	.long	1077382432
	.globl	const3
	.align 8
	.type	const3, @object
	.size	const3, 8
const3:
	.long	3264175145
	.long	1081084149
	.align 8
.LC2:
	.string	"Mit Makros: tmp1 = %f, tmp2 = %f\n"
	.align 8
.LC4:
	.string	"Mit Const: tmp1 = %f, tmp2 = %f\n"
	.align 8
.LC5:
	.string	"Unterprogramm: tmp1 = %f, tmp2 = %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-16(%rbp), %xmm1
	movsd	.LC1(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	leaq	.LC2(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movsd	.LC0(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-16(%rbp), %xmm1
	movsd	.LC3(%rip), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	leaq	.LC4(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	call	_Z3food@PLT
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	leaq	.LC5(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1074003968
	.align 8
.LC1:
	.long	1271310320
	.long	1074039095
	.align 8
.LC3:
	.long	3264175145
	.long	1081084149
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
