#include <stdio.h>

extern int add(int v1, int v2); // アセンブリ言語で定義した関数

int main(void) {
    int r = add(1, 2);
    printf("r = %d\n", r);
}
