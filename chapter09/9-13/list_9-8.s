	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15, 4	sdk_version 10, 15, 4
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	_n@GOTPCREL(%rip), %rax
	movl	$0, -4(%rbp)
	movl	$0, (%rax)
	movl	_b(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	_a(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movb	$0, %al
	callq	_printf
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	_tmp@GOTPCREL(%rip), %rax
	movl	_a(%rip), %ecx
	addl	_b(%rip), %ecx
	movl	%ecx, (%rax)
	cmpl	$0, %ecx
	jle	LBB0_5
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_tmp@GOTPCREL(%rip), %rax
	movl	_a(%rip), %ecx
	movl	%ecx, _b(%rip)
	movl	(%rax), %ecx
	movl	%ecx, _a(%rip)
	cmpl	$1000, _a(%rip)         ## imm = 0x3E8
	jle	LBB0_4
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_n@GOTPCREL(%rip), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	_a(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	jmp	LBB0_1
LBB0_5:
	movq	_n@GOTPCREL(%rip), %rax
	movl	(%rax), %esi
	leaq	L_.str.1(%rip), %rdi
	xorl	%ecx, %ecx
	movb	%cl, %dl
	movb	%dl, %al
	movl	%ecx, -12(%rbp)         ## 4-byte Spill
	movb	%dl, -13(%rbp)          ## 1-byte Spill
	callq	_printf
	movl	_a(%rip), %esi
	movl	_b(%rip), %edx
	movq	_tmp@GOTPCREL(%rip), %rdi
	movl	(%rdi), %ecx
	leaq	L_.str.2(%rip), %rdi
	movb	-13(%rbp), %r8b         ## 1-byte Reload
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movb	%r8b, %al
	callq	_printf
	movl	-12(%rbp), %edi         ## 4-byte Reload
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	callq	_exit
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_a                      ## @a
	.p2align	2
_a:
	.long	1                       ## 0x1

	.globl	_b                      ## @b
	.p2align	2
_b:
	.long	1                       ## 0x1

	.comm	_n,4,2                  ## @n
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	" %10d\n"

	.comm	_tmp,4,2                ## @tmp
L_.str.1:                               ## @.str.1
	.asciz	"\n The number of values greater than 1000 is %d\n"

L_.str.2:                               ## @.str.2
	.asciz	"Final values are: a = 0x%08X b = 0x%08X tmp = 0x%08X"


.subsections_via_symbols
