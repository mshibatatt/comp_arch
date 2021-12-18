#include <bits/stdc++.h>
using namespace std;

vector<vector<unsigned int>> M(1000, vector<unsigned int>(1000));

struct Block {
    int tag;
    bitset<1024> value;

    Block() {
        tag = -1;
        value = bitset<1024>(0);
    }
};

struct Cache {
    vector<Block> blocks;
    int hit;

    Cache() {
        blocks.assign(64, Block());
        hit = 0;
    }

    int read(int row, int column) {
        int address = row*1000 + column;
        int offset = address & 0b11111;
        int block = (address >> 5) & 0b111111;
        int tag = (address >> 11);
        if (blocks[block].tag == tag) {
            hit++;
        } else {
            int _row = (tag << 11) / 1000;
            int _column = (tag << 11) % 1000;
            for (int i = 0; i < 32; i++) {
                for (int j = 0; j < 32; j++) {
                    blocks[block].value.set(i*32 + j, (M[_row][_column] >> j) & 1);
                }
                _column++;
                if (_column == 1000) {
                    _column = 0;
                    _row++;
                }
            }
            blocks[block].tag = tag;
        }
        return ((blocks[block].value >> (offset*32)) & bitset<1024>(0b11111)).to_ullong();
    }

    void reset() {
        blocks.assign(64, Block());
        hit = 0;
    }
};

int main() {
    Cache c;

    // 行ごと
    c.reset();
    for (int row = 0; row < 1000; row++) {
        for (int column = 0; column < 1000; column++) {
            c.read(row, column);
        }
    }
    cout << "Row   : " << c.hit << " (" << (double)c.hit*100.0 / (1000*1000) << "%)"<< endl;

    // 列ごと
    c.reset();
    for (int column = 0; column < 1000; column++) {
        for (int row = 0; row < 1000; row++) {
            c.read(row, column);
        }
    }
    cout << "Column: " << c.hit << " (" << (double)c.hit*100.0 / (1000*1000) << "%)"<< endl;
}
