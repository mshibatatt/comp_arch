#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <vector>

using namespace std;


vector<unsigned short> regs; // Virtual Register

int split_register(unsigned int R, int r1, int r2){
    
    unsigned short n1 = R >> 16;
    unsigned short n2 = R & 0xffff;

    regs[r1] = n1;
    regs[r2] = n2;

    return 0;
}

int add16(int r1, int r2, int dst1, int dst2){

    unsigned int add = regs[r1] + regs[r2];
    split_register(add, dst1, dst2);
    
    return 0;
}

int prod16(int r1, int r2, int dst1, int dst2){
    
    unsigned int prod = regs[r1] * regs[r2];
    split_register(prod, dst1, dst2);
    
    return 0;
}

int main() {

    regs.assign(30, 0);

    unsigned int R1; // 32bit non-negative integer
    unsigned int R2; //

    cin >> R1;
    cin >> R2;
    
    split_register(R1, 1, 2);
    split_register(R2, 3, 4);

    prod16(2, 4, 5, 6);
    prod16(1, 4, 7, 8);
    prod16(2, 3, 9, 10);
    prod16(1, 3, 11, 12);

    regs[16] = regs[6];

    add16(5, 8, 17, 15); 
    add16(10, 15, 18, 15); 
    add16(17, 18, 13, 14); //process carry

    add16(7, 14, 17, 14); 
    add16(9, 14, 18, 14); 
    add16(12, 14, 19, 14); 
    add16(17, 18, 20, 13); //process carry
    add16(19, 13, 20, 13); //process carry. r20 never overflows

    add16(11, 13, 20, 13); //r20 never overflows

    // Print the results (to confirm the result, I use 64 bit int)
    unsigned long long res = regs[13];
    res = (res << 16) | regs[14];
    res = (res << 16) | regs[15];
    res = (res << 16) | regs[16];

    cout << res;

    return 0;
}
