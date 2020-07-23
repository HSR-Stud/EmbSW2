	.file	"StackTest.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN7StackUIIiLi3EEC2Ev,"axG",@progbits,_ZN7StackUIIiLi3EEC5Ev,comdat
	.align 2
	.weak	_ZN7StackUIIiLi3EEC2Ev
	.type	_ZN7StackUIIiLi3EEC2Ev, @function
_ZN7StackUIIiLi3EEC2Ev:
.LFB1503:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5StackIiLi3EEC1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1503:
	.size	_ZN7StackUIIiLi3EEC2Ev, .-_ZN7StackUIIiLi3EEC2Ev
	.weak	_ZN7StackUIIiLi3EEC1Ev
	.set	_ZN7StackUIIiLi3EEC1Ev,_ZN7StackUIIiLi3EEC2Ev
	.section	.text._ZN7StackUIIiLi4EEC2Ev,"axG",@progbits,_ZN7StackUIIiLi4EEC5Ev,comdat
	.align 2
	.weak	_ZN7StackUIIiLi4EEC2Ev
	.type	_ZN7StackUIIiLi4EEC2Ev, @function
_ZN7StackUIIiLi4EEC2Ev:
.LFB1506:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5StackIiLi4EEC1Ev
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1506:
	.size	_ZN7StackUIIiLi4EEC2Ev, .-_ZN7StackUIIiLi4EEC2Ev
	.weak	_ZN7StackUIIiLi4EEC1Ev
	.set	_ZN7StackUIIiLi4EEC1Ev,_ZN7StackUIIiLi4EEC2Ev
	.text
	.globl	main
	.type	main, @function
main:
.LFB1501:
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
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7StackUIIiLi3EEC1Ev
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7StackUIIiLi3EE6dialogEv
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7StackUIIiLi4EEC1Ev
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN7StackUIIiLi4EE6dialogEv
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1501:
	.size	main, .-main
	.section	.text._ZN5StackIiLi3EEC2Ev,"axG",@progbits,_ZN5StackIiLi3EEC5Ev,comdat
	.align 2
	.weak	_ZN5StackIiLi3EEC2Ev
	.type	_ZN5StackIiLi3EEC2Ev, @function
_ZN5StackIiLi3EEC2Ev:
.LFB1745:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, 12(%rax)
	movq	-8(%rbp), %rax
	movb	$0, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1745:
	.size	_ZN5StackIiLi3EEC2Ev, .-_ZN5StackIiLi3EEC2Ev
	.weak	_ZN5StackIiLi3EEC1Ev
	.set	_ZN5StackIiLi3EEC1Ev,_ZN5StackIiLi3EEC2Ev
	.section	.rodata
	.align 8
.LC0:
	.string	"\n\nOperation (Quit, pUsh, pOp, peeK, isEmpty) "
.LC1:
	.string	"\nElement to push: "
.LC2:
	.string	"\nError: Stack full."
	.align 8
.LC3:
	.string	"\nError: Stack is empty (nothing to pop)."
.LC4:
	.string	"\nPopped element "
	.align 8
.LC5:
	.string	"\nError: Stack is empty (nothing to peek)."
.LC6:
	.string	"\nPeeked element "
.LC7:
	.string	"\nStack is empty."
.LC8:
	.string	"\nStack contains elements."
.LC9:
	.string	"\nInvalid operation."
	.section	.text._ZN7StackUIIiLi3EE6dialogEv,"axG",@progbits,_ZN7StackUIIiLi3EE6dialogEv,comdat
	.align 2
	.weak	_ZN7StackUIIiLi3EE6dialogEv
	.type	_ZN7StackUIIiLi3EE6dialogEv, @function
_ZN7StackUIIiLi3EE6dialogEv:
.LFB1747:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$0, -13(%rbp)
.L24:
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-13(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_@PLT
	movzbl	-13(%rbp), %eax
	movsbl	%al, %eax
	subl	$69, %eax
	cmpl	$48, %eax
	ja	.L8
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L10(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L10(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata._ZN7StackUIIiLi3EE6dialogEv,"aG",@progbits,_ZN7StackUIIiLi3EE6dialogEv,comdat
	.align 4
	.align 4
.L10:
	.long	.L9-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L11-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L12-.L10
	.long	.L8-.L10
	.long	.L26-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L14-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L9-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L11-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L12-.L10
	.long	.L8-.L10
	.long	.L26-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L8-.L10
	.long	.L14-.L10
	.section	.text._ZN7StackUIIiLi3EE6dialogEv,"axG",@progbits,_ZN7StackUIIiLi3EE6dialogEv,comdat
.L14:
	leaq	.LC1(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZNSirsERi@PLT
	movq	-24(%rbp), %rax
	leaq	-12(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5StackIiLi3EE4pushERKi
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi3EE8wasErrorEv
	testb	%al, %al
	je	.L27
	leaq	.LC2(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L27
.L12:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5StackIiLi3EE3popEv
	movl	%eax, -12(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi3EE8wasErrorEv
	testb	%al, %al
	je	.L17
	leaq	.LC3(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L15
.L17:
	leaq	.LC4(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	jmp	.L15
.L11:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi3EE4peekEv
	movl	%eax, -12(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi3EE8wasErrorEv
	testb	%al, %al
	je	.L19
	leaq	.LC5(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L15
.L19:
	leaq	.LC6(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	jmp	.L15
.L9:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi3EE7isEmptyEv
	testb	%al, %al
	je	.L21
	leaq	.LC7(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L15
.L21:
	leaq	.LC8(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L15
.L8:
	leaq	.LC9(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L15
.L26:
	nop
	jmp	.L15
.L27:
	nop
.L15:
	movzbl	-13(%rbp), %eax
	cmpb	$81, %al
	je	.L28
	movzbl	-13(%rbp), %eax
	cmpb	$113, %al
	je	.L28
	jmp	.L24
.L28:
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L25
	call	__stack_chk_fail@PLT
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1747:
	.size	_ZN7StackUIIiLi3EE6dialogEv, .-_ZN7StackUIIiLi3EE6dialogEv
	.section	.text._ZN5StackIiLi4EEC2Ev,"axG",@progbits,_ZN5StackIiLi4EEC5Ev,comdat
	.align 2
	.weak	_ZN5StackIiLi4EEC2Ev
	.type	_ZN5StackIiLi4EEC2Ev, @function
_ZN5StackIiLi4EEC2Ev:
.LFB1749:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, 16(%rax)
	movq	-8(%rbp), %rax
	movb	$0, 20(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1749:
	.size	_ZN5StackIiLi4EEC2Ev, .-_ZN5StackIiLi4EEC2Ev
	.weak	_ZN5StackIiLi4EEC1Ev
	.set	_ZN5StackIiLi4EEC1Ev,_ZN5StackIiLi4EEC2Ev
	.section	.text._ZN7StackUIIiLi4EE6dialogEv,"axG",@progbits,_ZN7StackUIIiLi4EE6dialogEv,comdat
	.align 2
	.weak	_ZN7StackUIIiLi4EE6dialogEv
	.type	_ZN7StackUIIiLi4EE6dialogEv, @function
_ZN7StackUIIiLi4EE6dialogEv:
.LFB1751:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$0, -13(%rbp)
.L47:
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-13(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_@PLT
	movzbl	-13(%rbp), %eax
	movsbl	%al, %eax
	subl	$69, %eax
	cmpl	$48, %eax
	ja	.L31
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L33(%rip), %rax
	movl	(%rdx,%rax), %eax
	movslq	%eax, %rdx
	leaq	.L33(%rip), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata._ZN7StackUIIiLi4EE6dialogEv,"aG",@progbits,_ZN7StackUIIiLi4EE6dialogEv,comdat
	.align 4
	.align 4
.L33:
	.long	.L32-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L34-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L35-.L33
	.long	.L31-.L33
	.long	.L49-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L37-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L32-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L34-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L35-.L33
	.long	.L31-.L33
	.long	.L49-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L31-.L33
	.long	.L37-.L33
	.section	.text._ZN7StackUIIiLi4EE6dialogEv,"axG",@progbits,_ZN7StackUIIiLi4EE6dialogEv,comdat
.L37:
	leaq	.LC1(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZNSirsERi@PLT
	movq	-24(%rbp), %rax
	leaq	-12(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN5StackIiLi4EE4pushERKi
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi4EE8wasErrorEv
	testb	%al, %al
	je	.L50
	leaq	.LC2(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L50
.L35:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5StackIiLi4EE3popEv
	movl	%eax, -12(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi4EE8wasErrorEv
	testb	%al, %al
	je	.L40
	leaq	.LC3(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L38
.L40:
	leaq	.LC4(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	jmp	.L38
.L34:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi4EE4peekEv
	movl	%eax, -12(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi4EE8wasErrorEv
	testb	%al, %al
	je	.L42
	leaq	.LC5(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L38
.L42:
	leaq	.LC6(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	jmp	.L38
.L32:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi4EE7isEmptyEv
	testb	%al, %al
	je	.L44
	leaq	.LC7(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L38
.L44:
	leaq	.LC8(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L38
.L31:
	leaq	.LC9(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	jmp	.L38
.L49:
	nop
	jmp	.L38
.L50:
	nop
.L38:
	movzbl	-13(%rbp), %eax
	cmpb	$81, %al
	je	.L51
	movzbl	-13(%rbp), %eax
	cmpb	$113, %al
	je	.L51
	jmp	.L47
.L51:
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L48
	call	__stack_chk_fail@PLT
.L48:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1751:
	.size	_ZN7StackUIIiLi4EE6dialogEv, .-_ZN7StackUIIiLi4EE6dialogEv
	.section	.text._ZN5StackIiLi3EE4pushERKi,"axG",@progbits,_ZN5StackIiLi3EE4pushERKi,comdat
	.align 2
	.weak	_ZN5StackIiLi3EE4pushERKi
	.type	_ZN5StackIiLi3EE4pushERKi, @function
_ZN5StackIiLi3EE4pushERKi:
.LFB1861:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi3EE6isFullEv
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, 16(%rax)
	movq	-8(%rbp), %rax
	movzbl	16(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L54
	movq	-8(%rbp), %rax
	movl	12(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 12(%rax)
.L54:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1861:
	.size	_ZN5StackIiLi3EE4pushERKi, .-_ZN5StackIiLi3EE4pushERKi
	.section	.text._ZNK5StackIiLi3EE8wasErrorEv,"axG",@progbits,_ZNK5StackIiLi3EE8wasErrorEv,comdat
	.align 2
	.weak	_ZNK5StackIiLi3EE8wasErrorEv
	.type	_ZNK5StackIiLi3EE8wasErrorEv, @function
_ZNK5StackIiLi3EE8wasErrorEv:
.LFB1862:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	16(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1862:
	.size	_ZNK5StackIiLi3EE8wasErrorEv, .-_ZNK5StackIiLi3EE8wasErrorEv
	.section	.text._ZN5StackIiLi3EE3popEv,"axG",@progbits,_ZN5StackIiLi3EE3popEv,comdat
	.align 2
	.weak	_ZN5StackIiLi3EE3popEv
	.type	_ZN5StackIiLi3EE3popEv, @function
_ZN5StackIiLi3EE3popEv:
.LFB1863:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi3EE7isEmptyEv
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, 16(%rax)
	movq	-8(%rbp), %rax
	movzbl	16(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L58
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	leal	-1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 12(%rax)
	movq	-8(%rbp), %rax
	movl	12(%rax), %edx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	jmp	.L59
.L58:
	movl	$0, %eax
.L59:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1863:
	.size	_ZN5StackIiLi3EE3popEv, .-_ZN5StackIiLi3EE3popEv
	.section	.text._ZNK5StackIiLi3EE4peekEv,"axG",@progbits,_ZNK5StackIiLi3EE4peekEv,comdat
	.align 2
	.weak	_ZNK5StackIiLi3EE4peekEv
	.type	_ZNK5StackIiLi3EE4peekEv, @function
_ZNK5StackIiLi3EE4peekEv:
.LFB1864:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi3EE7isEmptyEv
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, 16(%rax)
	movq	-8(%rbp), %rax
	movzbl	16(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L61
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	leal	-1(%rax), %edx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	jmp	.L62
.L61:
	movl	$0, %eax
.L62:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1864:
	.size	_ZNK5StackIiLi3EE4peekEv, .-_ZNK5StackIiLi3EE4peekEv
	.section	.text._ZNK5StackIiLi3EE7isEmptyEv,"axG",@progbits,_ZNK5StackIiLi3EE7isEmptyEv,comdat
	.align 2
	.weak	_ZNK5StackIiLi3EE7isEmptyEv
	.type	_ZNK5StackIiLi3EE7isEmptyEv, @function
_ZNK5StackIiLi3EE7isEmptyEv:
.LFB1865:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	testl	%eax, %eax
	sete	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1865:
	.size	_ZNK5StackIiLi3EE7isEmptyEv, .-_ZNK5StackIiLi3EE7isEmptyEv
	.section	.text._ZN5StackIiLi4EE4pushERKi,"axG",@progbits,_ZN5StackIiLi4EE4pushERKi,comdat
	.align 2
	.weak	_ZN5StackIiLi4EE4pushERKi
	.type	_ZN5StackIiLi4EE4pushERKi, @function
_ZN5StackIiLi4EE4pushERKi:
.LFB1866:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi4EE6isFullEv
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, 20(%rax)
	movq	-8(%rbp), %rax
	movzbl	20(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L67
	movq	-8(%rbp), %rax
	movl	16(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	%ecx, (%rax,%rdx,4)
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 16(%rax)
.L67:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1866:
	.size	_ZN5StackIiLi4EE4pushERKi, .-_ZN5StackIiLi4EE4pushERKi
	.section	.text._ZNK5StackIiLi4EE8wasErrorEv,"axG",@progbits,_ZNK5StackIiLi4EE8wasErrorEv,comdat
	.align 2
	.weak	_ZNK5StackIiLi4EE8wasErrorEv
	.type	_ZNK5StackIiLi4EE8wasErrorEv, @function
_ZNK5StackIiLi4EE8wasErrorEv:
.LFB1867:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	20(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1867:
	.size	_ZNK5StackIiLi4EE8wasErrorEv, .-_ZNK5StackIiLi4EE8wasErrorEv
	.section	.text._ZN5StackIiLi4EE3popEv,"axG",@progbits,_ZN5StackIiLi4EE3popEv,comdat
	.align 2
	.weak	_ZN5StackIiLi4EE3popEv
	.type	_ZN5StackIiLi4EE3popEv, @function
_ZN5StackIiLi4EE3popEv:
.LFB1868:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi4EE7isEmptyEv
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, 20(%rax)
	movq	-8(%rbp), %rax
	movzbl	20(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L71
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	leal	-1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 16(%rax)
	movq	-8(%rbp), %rax
	movl	16(%rax), %edx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	jmp	.L72
.L71:
	movl	$0, %eax
.L72:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1868:
	.size	_ZN5StackIiLi4EE3popEv, .-_ZN5StackIiLi4EE3popEv
	.section	.text._ZNK5StackIiLi4EE4peekEv,"axG",@progbits,_ZNK5StackIiLi4EE4peekEv,comdat
	.align 2
	.weak	_ZNK5StackIiLi4EE4peekEv
	.type	_ZNK5StackIiLi4EE4peekEv, @function
_ZNK5StackIiLi4EE4peekEv:
.LFB1869:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK5StackIiLi4EE7isEmptyEv
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movb	%dl, 20(%rax)
	movq	-8(%rbp), %rax
	movzbl	20(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L74
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	leal	-1(%rax), %edx
	movq	-8(%rbp), %rax
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	jmp	.L75
.L74:
	movl	$0, %eax
.L75:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1869:
	.size	_ZNK5StackIiLi4EE4peekEv, .-_ZNK5StackIiLi4EE4peekEv
	.section	.text._ZNK5StackIiLi4EE7isEmptyEv,"axG",@progbits,_ZNK5StackIiLi4EE7isEmptyEv,comdat
	.align 2
	.weak	_ZNK5StackIiLi4EE7isEmptyEv
	.type	_ZNK5StackIiLi4EE7isEmptyEv, @function
_ZNK5StackIiLi4EE7isEmptyEv:
.LFB1870:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	testl	%eax, %eax
	sete	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1870:
	.size	_ZNK5StackIiLi4EE7isEmptyEv, .-_ZNK5StackIiLi4EE7isEmptyEv
	.section	.text._ZNK5StackIiLi3EE6isFullEv,"axG",@progbits,_ZNK5StackIiLi3EE6isFullEv,comdat
	.align 2
	.weak	_ZNK5StackIiLi3EE6isFullEv
	.type	_ZNK5StackIiLi3EE6isFullEv, @function
_ZNK5StackIiLi3EE6isFullEv:
.LFB1906:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	$3, %eax
	sete	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1906:
	.size	_ZNK5StackIiLi3EE6isFullEv, .-_ZNK5StackIiLi3EE6isFullEv
	.section	.text._ZNK5StackIiLi4EE6isFullEv,"axG",@progbits,_ZNK5StackIiLi4EE6isFullEv,comdat
	.align 2
	.weak	_ZNK5StackIiLi4EE6isFullEv
	.type	_ZNK5StackIiLi4EE6isFullEv, @function
_ZNK5StackIiLi4EE6isFullEv:
.LFB1907:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	cmpl	$4, %eax
	sete	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1907:
	.size	_ZNK5StackIiLi4EE6isFullEv, .-_ZNK5StackIiLi4EE6isFullEv
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2011:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L84
	cmpl	$65535, -8(%rbp)
	jne	.L84
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L84:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2011:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2012:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2012:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
