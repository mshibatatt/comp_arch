## 3.3

> 実行に使われるコンピュータが、整数の表現にビッグエンディアンを使うのか、リトルエンディアンを使うのかを判定するコンピュータプログラムを書きましょう。

```bash
python3 -c "import sys; print(sys.byteorder)"
```
このコードで`little`と出力されれば、リトルエンディアン。`big`と出力されれば、ビッグエンディアン。

## 3.8

> 8ビットで可能な２進数のすべてと、それぞれの「2の補数」表現を表示する、Cのプログラムを書きましょう。

```C++　
#include<iostream>
#include<bitset>
using namespace std;

int main(){

  // 8ビットのビット列をすべて列挙する
  for (int a = 0; a < (1 << 8); ++a) {

    // ビット列の作成
    bitset<8> x(a);
    cout << "Original: " << a <<
    " Complement: " << (int) ~(a) <<
    " Original Bit: " << x <<
    " Complement Bit: " << ~x << endl;
  }
}
```


## 3.13
