int a = 1, b = 1, n;

int main(void) {
    
    n = 0;
    while ( (a = a + b) > 0 ) {
        b = a - b;
        if (a > 1000) {
            n++;
        }
    }

    return 0;
}
