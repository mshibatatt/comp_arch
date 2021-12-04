## 9.2
> プログラマがアセンブリ言語を読むとき、コメントはどこにあると思いますか。

各セクションのはじめにブロックコメントして目的が書いてあり、また、各行に詳細な目的が書いてある。  

## 9.7
> アセンブリ言語で、3個の変数を宣言し、それらに1と2と3を代入し、`printf`で呼び出して3つの値を書式付きで表示するプログラムを書きましょう。

9_7.s  下記で実行可能.
```
cd chapter09/9_7
gcc -o 9_7.o 9_7.s
./9_7.o
```
また、同様のプログラムをC言語で記述したのもが9_7_c.cであり、`gcc -S 9_7_c.c` で模範解答が確認できる（なくてもコードが実行できる箇所は多い）。

c.f. [Assembly language explanation](https://stackoverflow.com/questions/17794533/what-does-this-assembly-language-code-mean), 
[Explanation about stack and function prologue](https://qiita.com/tobira-code/items/75d3034aed8bb9828981)


## 9.12
> リスト9-10とリスト9-11にあるフィボナッチプログラムのx86版とARM版を比較しましょう。コードの量が多くなりそうなのは、どちらのバージョンですか？その理由は？

ARM版。各変数についてメモリアドレスを固定した箇所、和を取る前に常に最新の値に反映させる箇所、fmtのr0への格納に2行使う箇所でそれぞれコードが長くなっているから。