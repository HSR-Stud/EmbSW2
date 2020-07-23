	.file	"main.cpp"
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	movl	$0, -4(%rsp)
	movl	$15, -4(%rsp)
	movl	-4(%rsp), %eax
	orl	$48, %eax
	movl	%eax, -4(%rsp)
	movl	-4(%rsp), %eax
	andl	$96, %eax
	movl	%eax, -4(%rsp)
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
