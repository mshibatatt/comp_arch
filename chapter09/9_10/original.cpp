int a = 1, b = 1, n, tmp;

int main(void) {

    n = 0;
    while ( (tmp = a + b) > 0 ) {
        b = a;
        a = tmp;
        if (a > 1000) {
            n++;
        }
    }

    return 0;
}
