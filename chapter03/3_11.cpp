#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    byte byteArray[N];

    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        byteArray[i] = (byte)x;
    }

    for (int i = 0; i < N; i++) {
        printf("%02x", byteArray[i]);
        if (i % 4 == 3) printf(" ");
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        if (isprint((int)byteArray[i])) cout << (char)byteArray[i];
        else cout << ".";
        if (i % 4 == 3) cout << " ";
    }
    cout << endl;
}
