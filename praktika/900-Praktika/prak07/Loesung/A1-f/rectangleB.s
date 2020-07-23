	.file	"rectangleB.cpp"
	.text
	.p2align 4,,15
	.globl	_Z13getRectangleBRK9Rectangle
	.type	_Z13getRectangleBRK9Rectangle, @function
_Z13getRectangleBRK9Rectangle:
.LFB6:
	.cfi_startproc
	movsd	(%rdi), %xmm1
	movsd	8(%rdi), %xmm0
	mulsd	%xmm1, %xmm0
	divsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE6:
	.size	_Z13getRectangleBRK9Rectangle, .-_Z13getRectangleBRK9Rectangle
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
