    .data
a:  .long   1
b:  .long   1
    .comm n, 4, 4
    .comm tmp 4,4

fmt1: .string " %10d\n"
fmt2: .string "\nThe number of values greater than 1000 is %d\n"
fmt3: .string "Final values are: a=0x%08X b=0x%08X tmp=0x%08X\n"

    .text
    .globl main

main:

    movl $0, n
    movl n, %esi # あとでnに値を渡さないようにレジスタに登録
    movl b, %ebx
    movl $fmt1, %edi
    movl $0 %ecx
    call printf
    movl a, %eax
    movl $fmt1, %edi
    movl $0 %ecx # どうもprintfの前に$0を入れるっぽい？
    call printf

while:

    addl %ebx, %eax # aの値にbを足す, tmpの計算が%eaxに(つまりここでaへの代入も終了)
    testl %eax, %eax
    jle endwhile
    movl %eax, %ebx # aの値が含まれているレジスタの情報ををbのレジスタににわたす
    cmpl $1000, %eax
    jle endif
    addl $1, %esi # nに1を足す

endif:
    movl $fmt1, %edi
    movl $0 %ecx
    call printf
    jmp while

endwhile:
    movl $fmt2, %edi
    movl $0 %ecx
    call printf
    movl $fmt3, %edi
    movl $0 %ecx
    call printf
    call exit
