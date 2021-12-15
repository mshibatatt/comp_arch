	.file	"original.cpp"
	.text
	.globl	a
	.data
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	1
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	1
	.globl	n
	.bss
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.zero	4
	.globl	tmp
	.align 4
	.type	tmp, @object
	.size	tmp, 4
tmp:
	.zero	4
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, n(%rip)
.L4:
	movl	a(%rip), %edx
	movl	b(%rip), %eax
	addl	%edx, %eax
	movl	%eax, tmp(%rip)
	movl	tmp(%rip), %eax
	testl	%eax, %eax
	setg	%al
	testb	%al, %al
	je	.L2
	movl	a(%rip), %eax
	movl	%eax, b(%rip)
	movl	tmp(%rip), %eax
	movl	%eax, a(%rip)
	movl	a(%rip), %eax
	cmpl	$1000, %eax
	jle	.L4
	movl	n(%rip), %eax
	addl	$1, %eax
	movl	%eax, n(%rip)
	jmp	.L4
.L2:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
