#include <stdio.h>
#include <ctype.h>

int main() {
    int i = 48;
    if (isdigit(i)) {
        // ASCII系なら10進数で 48 は 0 なので true
        printf("ASCII");
        printf("\n");
    } else {
        // EBCDICで 48 はないので false
        printf("EBCDIC\n");
        printf("\n");
    }
    return 0;
}
