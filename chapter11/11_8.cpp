#include <iostream>
#include <vector>
using namespace std;

vector<int> M(1000, 0);

int fetch(int address, int offset) {
    if (0 <= offset && offset <= 3) {
        return (M[address] << (offset*8)) & 0xff;
    } else {
        return M[address];
    }
}

void store(int address, int offset, int value) {
    if (0 <= offset && offset <= 3) {
        M[address] = M[address] - (fetch(address, offset) >> (offset*8)) + (value << (offset*8));
    } else {
        M[address] = value;
    }
}

int main() {
    while (true) {
        cout << "'fetch' or 'store'?: ";
        string op;
        cin >> op;
        if (op == "fetch") {
            cout << "address?: ";
            int address;
            cin >> address;
            cout << "offset?: ";
            int offset;
            cin >> offset;
            cout << fetch(address, offset) << endl;
        } else if (op == "store") {
            cout << "address?: ";
            int address;
            cin >> address;
            cout << "offset?: ";
            int offset;
            cin >> offset;
            cout << "value?: ";
            int value;
            cin >> value;
            store(address, offset, value);
        } else {
            break;
        }
    }
}
