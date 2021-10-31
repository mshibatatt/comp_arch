#include <iostream>
#include <stdio.h>
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
}
