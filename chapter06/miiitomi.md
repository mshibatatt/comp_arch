## 6.2
>図 6‒2 を参考にして、次の命令がメモリに格納されているとき、個々のビットがどうなるかを示しなさい。
    `add  r1, r14, r9`

| 演算 | reg A | reg B | dst reg | offset |
| :--: | :--: | :--:   | :--:   | :--:   |  
| 00001 | 1110 | 1001 | 0001 | 000000000000000 |

## 6.7
>`jump`命令を実行する時に, ALUが実行する演算はなんですか？

加算.
- ALUは jump 実行時 reg Aの値とoffsetを受け取って, 加算した値をM3, M1経由でプログラムカウンタに渡す.

## 6.12
>図 6‒8 で、マルチプレクサ M3 が ALU からの入力を選択するのは、どの命令ですか？

add と jump.
- add 実行時、ALUはreg Aの値とreg Bの値の和を計算してM3経由でレジスタユニットに渡し、dst regに入れる.
- jump 実行時、ALUはreg Aの値とoffsetの和を計算してM3, M1経由でプログラムカウンタに渡す.
