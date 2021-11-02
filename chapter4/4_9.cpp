#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;

int main() {
    int N = pow(10, 7);
    vector<int> int_devidend(N), int_devisor(N);
    vector<float> float_devidend(N), float_devisor(N);

    mt19937 mt(0);
    uniform_int_distribution<int> uid(1, 100000000);
    for (int i = 0; i < N; i++) {
        int_devidend[i] = uid(mt);
        int_devisor[i] = uid(mt);
        float_devidend[i] = (float)int_devidend[i];
        float_devisor[i] = (float)float_devisor[i];
    }

    chrono::system_clock::time_point start, end;

    start = chrono::system_clock::now();
    for (int i = 0; i < N; i++) {
        int_devidend[i] / int_devisor[i];
    }
    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout << "int  : " << elapsed << " [ms]" << endl;

    start = chrono::system_clock::now();
    for (int i = 0; i < N; i++) {
        float_devidend[i] / float_devisor[i];
    }
    end = chrono::system_clock::now();
    elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout << "float: " << elapsed << " [ms]" << endl;
}
