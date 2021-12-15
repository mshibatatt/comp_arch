## 9.5
>商用プロセッサで使われたことのある引数渡しの機構を、3つあげてください.

教科書p167より,

1. 引数にメモリ内のスタックを使う
1. レジスタウィンドウを使って引数を渡す
1. 特殊な引数用レジスタを使う

## 9.10
>リスト9.8の例で、Cで書かれたフィボナッチプログラムを見ました.
>このプログラムを、もっと速くなるように書き直せますか? どうやって?

`tmp`を用いずとも実装できるので, よりレジスタの最適化ががしやすくなる（かも?）

`9_10.cpp` で計測した結果, 40~100倍程度の改善が見られた.
アセンブリ化されたコードのdiffをとった結果が以下である.
```
        .file   "original.cpp"                                |         .file   "modified.cpp"
        .globl  tmp                                           <
        .align 4                                              <
        .type   tmp, @object                                  <
        .size   tmp, 4                                        <
tmp:                                                          <
        .zero   4                                             <
        movl    %eax, tmp(%rip)                               |         movl    %eax, a(%rip)
        movl    tmp(%rip), %eax                               |         movl    a(%rip), %eax
        movl    a(%rip), %eax                                 |         movl    a(%rip), %edx
                                                              >         movl    b(%rip), %eax
                                                              >         subl    %eax, %edx
                                                              >         movl    %edx, %eax
        movl    tmp(%rip), %eax                               <
        movl    %eax, a(%rip)                                 <
```

`movl`の回数に差はなく`subl`の分, `modified.cpp`の方がコマンドが一つ多いので, あまりよく分からない.