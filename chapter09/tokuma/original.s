        .data

a:      .long 1
b:      .long 1
        .comm n, 4, 4
        .comm tmp, 4, 4

fmt1:   .string " %10d\n"
fmt2:   .string "\nThe number of values greater than 1000 is %d\n"
fmt3:   .string "Final values are: a=0x%08X b=0x%08X tmp=0x%08X\n"

        .text
        .global main

main:
    	movl $0, n
	    movl b, %esi
	    movl $fmt1, %edi
	    movl $0, %eax
	    call printf
	    movl a, %esi
	    movl $fmt1, %edi
	    movl $0, %eax
	    call printf
while:
        movl a, %eax
        addl b, %eax
        movl %eax, tmp
        testl %eax, %eax
        jle endwhile
        movl a, %eax
        movl %eax, b
        movl tmp, %eax
        movl %eax, a
        cmpl $1000, %eax
        jle endif
        movl n, %ebx
        addl $1, %ebx
        movl %ebx, n

endif:
        movl a, %esi
        movl $fmt1, %edi
        movl $0, %eax
        call printf
        jmp while

endwhile:
        movl n, %esi
        movl $fmt2, %edi
        movl $0, %eax
        call printf
        movl tmp, %ecx
        movl b, %edx
        movl a, %esi
        movl $fmt3, %edi
        movl $0, %eax
        call printf
        movl $0, %edi
        call exit
