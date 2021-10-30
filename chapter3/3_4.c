// 3.4 
// ある整数のビット並びを0と1で表示するコンピュータプログラムを書きましょう。
// 各ビットの間に1個の空白を入れ、さらに4ビットごとにもう1つ空白を加えます。
#include <stdio.h>
#include <string.h>  

int main(void){
    char* output[20], bit_s[1];
    int num, binary, bit, base, counter, negative;
    
    printf("type intger number\n");
	scanf("%d",&num);
    
    if(num == 0){
        printf("%d", 0);
        return 0;
    }else if(num < 0){
        negative = 1;
        num = -num-1;
        printf("negative number is not supprted\n");
        return 0;
    }else if(num >= 512){
        printf("too big!!\n");
    };

    // transform to binary
    binary = 0;
    counter = 0;
    base = 1;
    while(num > 0){
        bit = num % 2;
        num /= 2; // num is int
        binary += bit * base;
        base *= 10;
        counter += 1;
    };
    // printf("%d\n", binary);

    // format as char
    base /= 10;
    while(base > 0){
        bit = binary / base % 2;
        sprintf(bit_s, "%d", bit);
        // printf("bit_s:, %s, base: %d\n", bit_s, base);
        strcat(output, bit_s);
        strcat(output, " ");
        counter --;
        if(counter % 4 == 0){
            strcat(output, " ");
        };
        base /= 10;
    };

    printf("%s\n", output);
    return 0;
}