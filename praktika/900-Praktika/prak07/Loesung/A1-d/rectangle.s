	.file	"rectangle.cpp"
	.text
	.align 2
	.globl	_ZNK9Rectangle7getAreaEv
	.type	_ZNK9Rectangle7getAreaEv, @function
_ZNK9Rectangle7getAreaEv:
.LFB5:
	.cfi_startproc
	movsd	(%rdi), %xmm0
	mulsd	8(%rdi), %xmm0
	ret
	.cfi_endproc
.LFE5:
	.size	_ZNK9Rectangle7getAreaEv, .-_ZNK9Rectangle7getAreaEv
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
