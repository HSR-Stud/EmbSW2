	.file	"StackTest.cpp"
	.text
	.section	.rodata._ZN7StackUIIiLi3EE6dialogEv.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"\n\nOperation (Quit, pUsh, pOp, peeK, isEmpty) "
	.section	.rodata._ZN7StackUIIiLi3EE6dialogEv.str1.1,"aMS",@progbits,1
.LC1:
	.string	"\nElement to push: "
.LC2:
	.string	"\nPopped element "
.LC3:
	.string	"\nPeeked element "
.LC4:
	.string	"\nStack is empty."
.LC5:
	.string	"\nStack contains elements."
.LC6:
	.string	"\nInvalid operation."
.LC7:
	.string	"\nError: Stack full."
	.section	.rodata._ZN7StackUIIiLi3EE6dialogEv.str1.8
	.align 8
.LC8:
	.string	"\nError: Stack is empty (nothing to pop)."
	.align 8
.LC9:
	.string	"\nError: Stack is empty (nothing to peek)."
	.section	.text._ZN7StackUIIiLi3EE6dialogEv,"axG",@progbits,_ZN7StackUIIiLi3EE6dialogEv,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN7StackUIIiLi3EE6dialogEv
	.type	_ZN7StackUIIiLi3EE6dialogEv, @function
_ZN7StackUIIiLi3EE6dialogEv:
.LFB1818:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	.LC0(%rip), %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	.L4(%rip), %rbp
	leaq	_ZSt4cout(%rip), %rbx
	movq	%rdi, %r12
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	leaq	3(%rsp), %r14
	leaq	4(%rsp), %r15
	movb	$0, 3(%rsp)
	.p2align 4,,10
	.p2align 3
.L13:
	movl	$45, %edx
	movq	%r13, %rsi
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt3cin(%rip), %rdi
	movq	%r14, %rsi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_@PLT
	movzbl	3(%rsp), %eax
	leal	-69(%rax), %edx
	cmpb	$48, %dl
	ja	.L2
	movzbl	%dl, %edx
	movslq	0(%rbp,%rdx,4), %rdx
	addq	%rbp, %rdx
	jmp	*%rdx
	.section	.rodata._ZN7StackUIIiLi3EE6dialogEv,"aG",@progbits,_ZN7StackUIIiLi3EE6dialogEv,comdat
	.align 4
	.align 4
.L4:
	.long	.L3-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L5-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L6-.L4
	.long	.L2-.L4
	.long	.L7-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L8-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L3-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L5-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L6-.L4
	.long	.L2-.L4
	.long	.L7-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L8-.L4
	.section	.text._ZN7StackUIIiLi3EE6dialogEv,"axG",@progbits,_ZN7StackUIIiLi3EE6dialogEv,comdat
	.p2align 4,,10
	.p2align 3
.L6:
	movl	(%r12), %eax
	testl	%eax, %eax
	sete	4(%r12)
	je	.L10
	movq	8(%r12), %rdx
	subl	$1, %eax
	leaq	.LC2(%rip), %rsi
	movl	%eax, (%r12)
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	$16, %edx
	movl	%eax, 4(%rsp)
.L18:
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	4(%rsp), %esi
	movq	%rbx, %rdi
	call	_ZNSolsEi@PLT
	movzbl	3(%rsp), %eax
.L7:
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L13
.L21:
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L20
	addq	$24, %rsp
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
	.p2align 4,,10
	.p2align 3
.L5:
	.cfi_restore_state
	movslq	(%r12), %rax
	testl	%eax, %eax
	sete	4(%r12)
	je	.L11
	movq	8(%r12), %rdx
	leaq	.LC3(%rip), %rsi
	movl	-4(%rdx,%rax,4), %eax
	movl	$16, %edx
	movl	%eax, 4(%rsp)
	jmp	.L18
	.p2align 4,,10
	.p2align 3
.L8:
	leaq	.LC1(%rip), %rsi
	movl	$18, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt3cin(%rip), %rdi
	movq	%r15, %rsi
	call	_ZNSirsERi@PLT
	movl	(%r12), %eax
	cmpl	$3, %eax
	sete	4(%r12)
	je	.L9
	movl	4(%rsp), %ecx
	movslq	%eax, %rdx
	addl	$1, %eax
	movl	%ecx, 16(%r12,%rdx,4)
	movl	%eax, (%r12)
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L13
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L3:
	movl	(%r12), %eax
	testl	%eax, %eax
	jne	.L12
	leaq	.LC4(%rip), %rsi
	movl	$16, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L13
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L2:
	leaq	.LC6(%rip), %rsi
	movl	$19, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L13
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L11:
	leaq	.LC9(%rip), %rsi
	movl	$41, %edx
	movq	%rbx, %rdi
	movl	$0, 4(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L13
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L10:
	leaq	.LC8(%rip), %rsi
	movl	$40, %edx
	movq	%rbx, %rdi
	movl	$0, 4(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L13
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L12:
	leaq	.LC5(%rip), %rsi
	movl	$25, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L13
	jmp	.L21
	.p2align 4,,10
	.p2align 3
.L9:
	leaq	.LC7(%rip), %rsi
	movl	$19, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L13
	jmp	.L21
.L20:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1818:
	.size	_ZN7StackUIIiLi3EE6dialogEv, .-_ZN7StackUIIiLi3EE6dialogEv
	.section	.text._ZN7StackUIIiLi4EE6dialogEv,"axG",@progbits,_ZN7StackUIIiLi4EE6dialogEv,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZN7StackUIIiLi4EE6dialogEv
	.type	_ZN7StackUIIiLi4EE6dialogEv, @function
_ZN7StackUIIiLi4EE6dialogEv:
.LFB1822:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	.LC0(%rip), %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	.L25(%rip), %rbp
	leaq	_ZSt4cout(%rip), %rbx
	movq	%rdi, %r12
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	leaq	3(%rsp), %r14
	leaq	4(%rsp), %r15
	movb	$0, 3(%rsp)
	.p2align 4,,10
	.p2align 3
.L34:
	movl	$45, %edx
	movq	%r13, %rsi
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt3cin(%rip), %rdi
	movq	%r14, %rsi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_@PLT
	movzbl	3(%rsp), %eax
	leal	-69(%rax), %edx
	cmpb	$48, %dl
	ja	.L23
	movzbl	%dl, %edx
	movslq	0(%rbp,%rdx,4), %rdx
	addq	%rbp, %rdx
	jmp	*%rdx
	.section	.rodata._ZN7StackUIIiLi4EE6dialogEv,"aG",@progbits,_ZN7StackUIIiLi4EE6dialogEv,comdat
	.align 4
	.align 4
.L25:
	.long	.L24-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L26-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L27-.L25
	.long	.L23-.L25
	.long	.L28-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L29-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L24-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L26-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L27-.L25
	.long	.L23-.L25
	.long	.L28-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L23-.L25
	.long	.L29-.L25
	.section	.text._ZN7StackUIIiLi4EE6dialogEv,"axG",@progbits,_ZN7StackUIIiLi4EE6dialogEv,comdat
	.p2align 4,,10
	.p2align 3
.L27:
	movl	(%r12), %eax
	testl	%eax, %eax
	sete	4(%r12)
	je	.L31
	movq	8(%r12), %rdx
	subl	$1, %eax
	leaq	.LC2(%rip), %rsi
	movl	%eax, (%r12)
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	$16, %edx
	movl	%eax, 4(%rsp)
.L39:
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	4(%rsp), %esi
	movq	%rbx, %rdi
	call	_ZNSolsEi@PLT
	movzbl	3(%rsp), %eax
.L28:
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L34
.L41:
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L40
	addq	$24, %rsp
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
	.p2align 4,,10
	.p2align 3
.L26:
	.cfi_restore_state
	movslq	(%r12), %rax
	testl	%eax, %eax
	sete	4(%r12)
	je	.L32
	movq	8(%r12), %rdx
	leaq	.LC3(%rip), %rsi
	movl	-4(%rdx,%rax,4), %eax
	movl	$16, %edx
	movl	%eax, 4(%rsp)
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L29:
	leaq	.LC1(%rip), %rsi
	movl	$18, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt3cin(%rip), %rdi
	movq	%r15, %rsi
	call	_ZNSirsERi@PLT
	movl	(%r12), %eax
	cmpl	$4, %eax
	sete	4(%r12)
	je	.L30
	movl	4(%rsp), %ecx
	movslq	%eax, %rdx
	addl	$1, %eax
	movl	%ecx, 16(%r12,%rdx,4)
	movl	%eax, (%r12)
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L34
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L24:
	movl	(%r12), %eax
	testl	%eax, %eax
	jne	.L33
	leaq	.LC4(%rip), %rsi
	movl	$16, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L34
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L23:
	leaq	.LC6(%rip), %rsi
	movl	$19, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L34
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L32:
	leaq	.LC9(%rip), %rsi
	movl	$41, %edx
	movq	%rbx, %rdi
	movl	$0, 4(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L34
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L31:
	leaq	.LC8(%rip), %rsi
	movl	$40, %edx
	movq	%rbx, %rdi
	movl	$0, 4(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L34
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L33:
	leaq	.LC5(%rip), %rsi
	movl	$25, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L34
	jmp	.L41
	.p2align 4,,10
	.p2align 3
.L30:
	leaq	.LC7(%rip), %rsi
	movl	$19, %edx
	movq	%rbx, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movzbl	3(%rsp), %eax
	andl	$-33, %eax
	cmpb	$81, %al
	jne	.L34
	jmp	.L41
.L40:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1822:
	.size	_ZN7StackUIIiLi4EE6dialogEv, .-_ZN7StackUIIiLi4EE6dialogEv
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1573:
	.cfi_startproc
	subq	$88, %rsp
	.cfi_def_cfa_offset 96
	movq	%rsp, %rdi
	movl	$0, (%rsp)
	movb	$0, 4(%rsp)
	movq	%fs:40, %rax
	movq	%rax, 72(%rsp)
	xorl	%eax, %eax
	leaq	16(%rdi), %rax
	movq	%rax, 8(%rsp)
	call	_ZN7StackUIIiLi3EE6dialogEv
	leaq	32(%rsp), %rdi
	movl	$0, 32(%rsp)
	movb	$0, 36(%rsp)
	leaq	16(%rdi), %rax
	movq	%rax, 40(%rsp)
	call	_ZN7StackUIIiLi4EE6dialogEv
	movq	72(%rsp), %rdx
	xorq	%fs:40, %rdx
	jne	.L45
	xorl	%eax, %eax
	addq	$88, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L45:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1573:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2082:
	.cfi_startproc
	leaq	_ZStL8__ioinit(%rip), %rdi
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2082:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
