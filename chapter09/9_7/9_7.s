# declear 3 variable, substitute 1, 2 and 3 respectively, and call printf
# same as follwing 9_7_c.c

# declear arguments of printf
V1:	.long	1
V2: .long	2
V3:	.long	3
fmt:	.string	"V1 is %d, V2 is %d, V3 is %d\n"

	.text
	.globl	main
main:
	
	pushq	%rbp	# Function prologue	
	movq	%rsp, %rbp	# Function prologue

	movl	V3(%rip), %ecx	# put arguments in reverse order
	movl	V2(%rip), %edx
	movl	V1(%rip), %esi
	leaq	fmt(%rip), %rdi
	movl	$0, %eax

	call	printf # call printf
	
	movl	$0, %eax # exit function
	leave
	ret
