## 7.1
> あるコンピュータアーキテクトが極度に遅いメモリを持つコンピュータのためにプロセッサを設計しています。そのアーキテクトは「0アドレス」アーキテクチャを選ぶでしょうか？その理由は？

選ばない。「0アドレス」アーキテクチャはオペランドをレジスタからではなくメモリからフェッチするため。  
c.f. p120

## 7.6
> プログラマが最大の即値オペランドより大きな値で変数をインクリメントしようとしたら、ある最適化コンパイラは2つの命令を生成します。例えば127以下の即値しか許さないコンピュータで、変数`x`を140だけインクリメントしようとしたら、コンパイル結果は次のシーケンスコードになりました。
```
load r7, x
add_immediate r7, 127
add_immediate t7, 13　<- r7のタイポかしらね
store r7, x
```
> なぜコンパイラはいったん140をメモリに格納してから、その値をレジスタ7に加算しないのでしょうか

メモリにアクセスするより即値のほうが速いから  
c.f. [メモリのアクセス時間とローカルメモリ](https://news.mynavi.jp/article/architecture-135/)

## 7.11
> ほとんどのコンパイラには頻繁に使われる変数をいちいちメモリに書き戻すよりレジスタに入れたままにしておくことを選ぶ最適化モジュールが含まれています。その最適化モジュールが回避している問題の性質にはどんな名前がありますか？

- Aliasing
    - In some architectures, assigning a value to one register can affect the value of another: this is called aliasing. For example the x86 architecture has four general purpose 32-bit registers that can also be used as 16-bit or 8-bits registers. In this case, assigning a 32-bits value to the eax register will affect the value of the al register.
- Pre-coloring
    - This problem is an act to force some variables to be assigned to particular registers. For example, in PowerPC calling conventions, parameters are commonly passed in R3-R10 and the return value is passed in R3.
- NP-Problem
    - Chaitin et al. showed that register allocation is a NP-complete problem. They reduce the graph coloring problem to the register allocation problem by showing that for an arbitrary graph, a program can be constructed such that the register allocation for the program (with registers representing nodes and machine registers representing available colors) would be a coloring for the original graph. As Graph Coloring is an NP-Hard problem and Register Allocation is in NP, this proves the NP-completeness of the problem

from [Wikipedia](https://en.wikipedia.org/wiki/Register_allocation)