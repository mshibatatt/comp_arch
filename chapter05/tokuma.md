## 5.2　
> あるコンピュータでは、算術演算のハードウェアによって、オペランドが個別のバンクにあることが要求されます。その場合、次の計算を行うには、どういう命令シーケンスが必要でしょうか？
```
 A <- B - C
 Q <- A * C
 W <- Q + A
 Z <- W - Q
```

オペランドが記録されるバンクを$a,b$とすると以下のようなシークエンスとなる。　
- $B$を$a$, $C$を$b$に割り当てる。
- $A = B-C$を計算し$a$に保存する。
- $Q = A*C$を計算し、$b$に保存する。
- $W = Q+A$を計算し、$a$に保存する。
- $Z = W-Q$を計算し,$b$に保存する。

## 5.7
> N段のパイプラインでステージ$i$には$t_i$の時間が必要だとします。ステージ間の遅延はないものとして、このパイプラインで1個の命令を扱うのに、開始から終了までに要する合計時間を求めてください。


1個の命令は逐次的にステージを進めていくため合計時間は$\sum_{i=1}^{N} t_i$.
