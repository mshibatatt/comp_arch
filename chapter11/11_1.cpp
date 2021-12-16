#include <stdio.h>

class word_array{
    public:
        int M[1000];
        int word_size = 4; // 1 word is 4 byte

    int fetch(int i);
    void store(int i, char ch);
};

int word_array::fetch(int i){
    int word_address = i / word_size; 
    int offset = i % word_size;
    int output = M[word_address] >> (offset * 8) & 0xff;
    return output;
}

void word_array::store(int i, char ch){
    int word_address = i / word_size; // 1 word is 4 byte
    int offset = i % word_size;
    
    int shifter = (3 - offset) * 8;
    int ch_int = (int)ch << shifter;
    // make off where to store
    int current_word = M[word_address] & ~(0x08 << shifter);
    
    M[word_address] = current_word | ch_int;
    return;
}

int main(){
    // M: word array
    // each int show 32 bit information
    word_array W;
    for(int i=0; i<1000; i++){
        W.M[i] = i;
    }
    W.store(19, 12);
    int a = W.fetch(19);
    printf("%x\n",a);

    return 0;
}