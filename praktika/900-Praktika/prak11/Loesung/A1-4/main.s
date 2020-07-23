	.file	"main.cpp"
	.text
	.section	.rodata
.LC0:
	.string	"A::foo1()"
	.section	.text._ZN1A4foo1Ev,"axG",@progbits,_ZN1A4foo1Ev,comdat
	.align 2
	.weak	_ZN1A4foo1Ev
	.type	_ZN1A4foo1Ev, @function
_ZN1A4foo1Ev:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_ZN1A4foo1Ev, .-_ZN1A4foo1Ev
	.section	.rodata
.LC1:
	.string	"A::foo2()"
	.section	.text._ZN1A4foo2Ev,"axG",@progbits,_ZN1A4foo2Ev,comdat
	.align 2
	.weak	_ZN1A4foo2Ev
	.type	_ZN1A4foo2Ev, @function
_ZN1A4foo2Ev:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN1A4foo2Ev, .-_ZN1A4foo2Ev
	.section	.rodata
.LC2:
	.string	"A::foo3()"
	.section	.text._ZN1A4foo3Ev,"axG",@progbits,_ZN1A4foo3Ev,comdat
	.align 2
	.weak	_ZN1A4foo3Ev
	.type	_ZN1A4foo3Ev, @function
_ZN1A4foo3Ev:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_ZN1A4foo3Ev, .-_ZN1A4foo3Ev
	.section	.rodata
.LC3:
	.string	"B::foo1()"
	.section	.text._ZN1B4foo1Ev,"axG",@progbits,_ZN1B4foo1Ev,comdat
	.align 2
	.weak	_ZN1B4foo1Ev
	.type	_ZN1B4foo1Ev, @function
_ZN1B4foo1Ev:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_ZN1B4foo1Ev, .-_ZN1B4foo1Ev
	.section	.rodata
.LC4:
	.string	"B::foo4()"
	.section	.text._ZN1B4foo4Ev,"axG",@progbits,_ZN1B4foo4Ev,comdat
	.align 2
	.weak	_ZN1B4foo4Ev
	.type	_ZN1B4foo4Ev, @function
_ZN1B4foo4Ev:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_ZN1B4foo4Ev, .-_ZN1B4foo4Ev
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
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	16+_ZTV1A(%rip), %rax
	movq	%rax, -24(%rbp)
	leaq	16+_ZTV1B(%rip), %rax
	movq	%rax, -16(%rbp)
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN1A4foo1Ev
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN1A4foo2Ev
	leaq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN1A4foo3Ev
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN1B4foo1Ev
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN1A4foo2Ev
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN1A4foo3Ev
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN1B4foo4Ev
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.weak	_ZTV1B
	.section	.data.rel.ro.local._ZTV1B,"awG",@progbits,_ZTV1B,comdat
	.align 8
	.type	_ZTV1B, @object
	.size	_ZTV1B, 40
_ZTV1B:
	.quad	0
	.quad	_ZTI1B
	.quad	_ZN1B4foo1Ev
	.quad	_ZN1A4foo2Ev
	.quad	_ZN1B4foo4Ev
	.weak	_ZTV1A
	.section	.data.rel.ro.local._ZTV1A,"awG",@progbits,_ZTV1A,comdat
	.align 8
	.type	_ZTV1A, @object
	.size	_ZTV1A, 32
_ZTV1A:
	.quad	0
	.quad	_ZTI1A
	.quad	_ZN1A4foo1Ev
	.quad	_ZN1A4foo2Ev
	.weak	_ZTI1B
	.section	.data.rel.ro._ZTI1B,"awG",@progbits,_ZTI1B,comdat
	.align 8
	.type	_ZTI1B, @object
	.size	_ZTI1B, 24
_ZTI1B:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS1B
	.quad	_ZTI1A
	.weak	_ZTS1B
	.section	.rodata._ZTS1B,"aG",@progbits,_ZTS1B,comdat
	.type	_ZTS1B, @object
	.size	_ZTS1B, 3
_ZTS1B:
	.string	"1B"
	.weak	_ZTI1A
	.section	.data.rel.ro._ZTI1A,"awG",@progbits,_ZTI1A,comdat
	.align 8
	.type	_ZTI1A, @object
	.size	_ZTI1A, 16
_ZTI1A:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS1A
	.weak	_ZTS1A
	.section	.rodata._ZTS1A,"aG",@progbits,_ZTS1A,comdat
	.type	_ZTS1A, @object
	.size	_ZTS1A, 3
_ZTS1A:
	.string	"1A"
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
