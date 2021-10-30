// 3.9
// 最大の正の整数に1を足し、その結果を使って、
// コンピュータが2の補数による演算を実装しているか判定するコンピュータプログラムを書きましょう。

#include <stdio.h>
#include <limits.h>

int main(){
    short int max_num = SHRT_MAX;
    short int nxt_num = max_num + 1;

    printf("max int is %d\n", max_num);
    printf("next is %d\n", nxt_num); 
    
    if(nxt_num == -max_num - 1){
        printf("2 complement\n");
    }else{
        printf("not 2 complement\n");
    };
    return 0;
}