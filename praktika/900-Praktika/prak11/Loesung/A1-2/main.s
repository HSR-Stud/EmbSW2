	.file	"main.cpp"
	.text
	.globl	const1
	.section	.rodata
	.align 4
	.type	const1, @object
	.size	const1, 4
const1:
	.long	64
	.globl	const2
	.align 4
	.type	const2, @object
	.size	const2, 4
const2:
	.long	128
	.globl	const3
	.align 4
	.type	const3, @object
	.size	const3, 4
const3:
	.long	256
	.align 8
.LC0:
	.string	"Mit Makros: tmp1 = %d, tmp2 = %d\n"
	.align 8
.LC1:
	.string	"Mit Enums: tmp1 = %d, tmp2 = %d\n"
	.align 8
.LC2:
	.string	"Mit Const: tmp1 = %d, tmp2 = %d\n"
	.align 8
.LC3:
	.string	"Unterprogramm: tmp1 = %d, tmp2 = %d\n"
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
	subq	$16, %rsp
	movl	$20, -8(%rbp)
	movl	$1, -4(%rbp)
	addl	$1, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$20, -8(%rbp)
	movl	$8, -4(%rbp)
	addl	$8, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$20, -8(%rbp)
	movl	$256, -4(%rbp)
	addl	$256, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	_Z3fooi@PLT
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
