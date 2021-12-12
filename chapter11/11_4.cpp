#include <iostream>

using namespace std;

int main(void){

    int N, s, a;

    cin>>N;

    for (int i=0; i<N; i++){
        cin>>s>>a;

        int addr_word = a / (s / 8); //8 bit is 1 byte
        int offset = a % (s / 8);

        cout<<addr_word<<" "<<offset<<endl;
    }

    return 0;
}