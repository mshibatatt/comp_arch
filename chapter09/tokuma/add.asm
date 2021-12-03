
GLOBAL _add    ; addをグローバルスコープで見えるようにする．

SECTION .text  ; TEXTセクション
_add:          ; addラベルの定義(C言語からaddとして参照できる)
    mov rax, rdi ; 第一引数をraxにコピー
    add rax, rsi ; 第二引数をraxに加算
    ret
