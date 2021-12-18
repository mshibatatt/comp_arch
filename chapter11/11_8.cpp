#include <bits/stdc++.h>
using namespace std;

// メモリのモデル. 4byte × 1000 ブロック.
vector<unsigned int> M(1000, 0);

int fetch(int byte_address) {
    int offset = byte_address & 0b11;
    int block_address = (byte_address >> 2);
    return (M[block_address] >> (offset * 8)) & 0xff;
}

void store(int byte_address, unsigned int value) {
    value = value & 0xff;
    int offset = byte_address & 0b11;
    int block_address = (byte_address >> 2);
    M[block_address] = M[block_address] - (((M[block_address] >> (offset*8)) & 0xff) << (offset * 8)) + (value << (offset * 8));
}

int main() {
    while (true) {
        cout << "'fetch' or 'store'?: ";
        string op;
        cin >> op;
        if (op == "fetch") {
            cout << "byte address?: ";
            int byte_address;
            cin >> byte_address;
            cout << fetch(byte_address) << endl;
        } else if (op == "store") {
            cout << "byte address?: ";
            int byte_address;
            cin >> byte_address;
            cout << "value?: ";
            unsigned int value;
            cin >> value;
            store(byte_address, value);
        } else {
            break;
        }
    }
}
