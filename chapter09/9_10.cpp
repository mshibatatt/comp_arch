#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <chrono>

using namespace std;

int a = 1, b = 1, n, tmp;

int main(void) {
    
    std::chrono::system_clock::time_point start, end;

    // Original Code
    start = std::chrono::system_clock::now();

    n = 0;
    printf(" %10d\n", b);
    printf(" %10d\n", a);
    while ( (tmp = a + b) > 0 ) {
        b = a;
        a = tmp;
        if (a > 1000) {
            n++;
        }
        printf(" %10d\n", a);
    }

    end = std::chrono::system_clock::now();

    double time1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Modified Code
    start = std::chrono::system_clock::now();

    n = 0;
    printf(" %10d\n", b);
    printf(" %10d\n", a);
    while ( (a = a + b) > 0 ) {
        b = a - b;
        if (a > 1000) {
            n++;
        }
        printf(" %10d\n", a);
    }

    end = std::chrono::system_clock::now();

    double time2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    
    // Print
    printf("\noriginal:%4.0f[μs]", time1);
    printf("\nmodified:%4.0f[μs]\n", time2);

    return 0;
}
