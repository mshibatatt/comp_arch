## 11.4
>上の練習問題を基にして、答えを計算するコンピュータプログラムを書きましょう.
プログラムは入力として、「ビット数で指定されるワードサイズ」と
「バイトアドレス」という2つの値のペアを、何度でも受け取るものとします。
それぞれの入力に対して、プログラムは1個のワードアドレスと、
ワード内オフセットを返すようにしましょう。
注意：ワードサイズはビット数で指定されますが、必ず2の冪乗でなければなりません。

ワードサイズのビット数を$s_i$, バイトアドレスを$a_i$として,
入力が以下の形式で行われると仮定する

$$\begin{matrix}
N &  \\
s_0 & a_{N-1} \\
\vdots & \vdots \\
s_{N-1} & a_{N-1}
\end{matrix}$$

プログラムは, `11_4.cpp`を参照のこと.

## 11.9
>PC用のメモリを見つけて、使われているチップの型名を識別し、
ベンダーの資料でチップの仕様を調べて、メモリの形式とスピードを判定しましょう。

自分のデスクトップPCのメモリはCORSAIRの[ENGEANCE LPX 32GB (2 x 16GB) DDR4 DRAM 3200MHz C16](https://www.corsair.com/ja/ja/%E3%82%AB%E3%83%86%E3%82%B4%E3%83%AA%E3%83%BC/%E8%A3%BD%E5%93%81/%E3%83%A1%E3%83%A2%E3%83%AA/VENGEANCE-LPX/p/CMK32GX4M2E3200C16#tab-tech-specs)
- メモリ形式はDDR4
- 3200MHz以下で動作するがSPDは2133MHz

ちなみに自分のMacbook Pro 2017は
- LPDDR3
- 2133MHz