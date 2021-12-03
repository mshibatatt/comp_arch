#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;


template<typename T> void iterative_devide(vector<T> &devidend, vector<T> &devisor) {
    int N = (int)devidend.size();
    chrono::system_clock::time_point start, end;

    start = chrono::system_clock::now();
    for (int i = 0; i < N; i++) {
       devidend[i] / devisor[i];
    }
    end = chrono::system_clock::now();
    int elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout  << elapsed << " [ms]" << endl;
}


int main() {
    int N = pow(10, 7);

    vector<int> int_devidend(N), int_devisor(N);  // 32-bit integer
    vector<long long> ll_devidend(N), ll_devisor(N);  // 64-bit integer
    vector<float> float_devidend(N), float_devisor(N);  // 32-bit floating point number
    vector<double> double_devidend(N), double_devisor(N);  // 64-bit floating point number

    // generate devidend and devisor randomly
    mt19937 mt(0);
    uniform_int_distribution<int> uid(1, (int)pow(10, 8));
    for (int i = 0; i < N; i++) {
        int a = uid(mt);
        int b = uid(mt);
        int_devidend[i] = (int)a;
        int_devisor[i] = (int)b;
        ll_devidend[i] = (long long)a;
        ll_devisor[i] = (long long)b;
        float_devidend[i] = (float)a;
        float_devisor[i] = (float)b;
        double_devidend[i] = (double)a;
        double_devisor[i] = (double)b;
    }

    cout << "int   : ";
    iterative_devide(int_devidend, int_devisor);

    cout << "ll    : ";
    iterative_devide(ll_devidend, ll_devisor);

    cout << "float : ";
    iterative_devide(float_devidend, float_devisor);

    cout << "double: ";
    iterative_devide(double_devidend, double_devisor);
}
