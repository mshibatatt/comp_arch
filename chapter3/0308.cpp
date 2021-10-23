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
