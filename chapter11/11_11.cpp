#include <stdio.h>

class word_array{
    // M: word array
    // each int show 32 bit information
    // example for memory storing 1, 3, 7, 15
    // 0000001 00000011 00000111 00001111
    // <- offset is 0,     offset is 3 -> 
    public:
        int M[1000];
        int word_size = 4; // 1 word is 4 byte

    int fetch(int i);
    void store(int i, int ch);
};

int word_array::fetch(int i){
    int word_address = i / word_size; 
    int offset = i % word_size;
    int shifter = (3 - offset) * 8;
    int output = M[word_address] >> shifter & 0xff;
    printf("word address is %d, and offset is %d\n", word_address, offset);
    printf("word contents is %x\n", M[word_address]);
    printf("output is %x\n", output);
    return output;
}

void word_array::store(int i, int ch){
    // ch should be 8 bit binary
    int word_address = i / word_size; // 1 word is 4 byte
    int offset = i % word_size;
    printf("set %x, into word address %d, and offset %d\n", ch, word_address, offset);
    
    int shifter = (3 - offset) * 8;
    ch = ch << shifter;
    // make off where to store
    int current_word = M[word_address] & ~(0xff << shifter);
    printf("original contents of memory is %x\n", M[word_address]);
    M[word_address] = current_word | ch;
    printf("new contents of memory is %x\n", M[word_address]);
    return;
}

int main(){
    word_array emulator;

    // initialize
    emulator.M[1] = 1;

    emulator.fetch(7);
    printf("\n");
    emulator.store(7, 0b11000011);
    printf("\n");
    emulator.store(5, 0b00110011);
    printf("\n");
    emulator.store(6, 0b00001111);
    printf("\n");
    emulator.store(4, 0b00000001);
    printf("\n");
    emulator.fetch(7);
    printf("\n");
    printf("memory array 1 is %x\n", emulator.M[1]);

    return 0;
}