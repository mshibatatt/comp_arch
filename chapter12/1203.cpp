#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric>
using namespace std;

double physicist(vector<vector<double>> a){

    double sum = 0;
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a[i].size(); ++j){
            sum += a[i][j];
        }
    }

    return sum;
};


double economist(vector<vector<double>> a){
    // ラムダ式で2回和を計算
    auto sum = std::accumulate(a.begin(), a.end(), 0, [](auto lhs, const auto& rhs) {
    return std::accumulate(rhs.begin(), rhs.end(), lhs);
});

    return sum;
}

int main(){
    // ----配列の用意 ----
    int num_elements = 10000;
    mt19937 mt(0);
    uniform_real_distribution<double> urd(0.0, 1.0);

    vector<vector<double>> a(num_elements, vector<double>(num_elements));
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a[i].size(); ++j){
            a[i][j] = urd(mt);
        }
    }


    float res_original, res_renewal;

    // ---- もともとのコードの速度計算 ----
    auto start = chrono::system_clock::now(); // 計測スタート時刻を保存
    res_original = physicist(a);
    auto end = chrono::system_clock::now(); // 計測終了時刻を保存
    auto dur = end - start;        // 要した時間を計算
    auto msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    // 要した時間をミリ秒（1/1000秒）に変換して表示
    std::cout << "Answer: " << res_original << " Original Cost: " << msec << " milli sec \n";

    // ---- 新コードの速度計算
    start = chrono::system_clock::now(); // 計測スタート時刻を保存
    res_renewal = economist(a);
    end = chrono::system_clock::now(); // 計測終了時刻を保存
    dur = end - start;        // 要した時間を計算
    msec = chrono::duration_cast<chrono::milliseconds>(dur).count();
    // 要した時間をミリ秒（1/1000秒）に変換して表示
    std::cout << "Answer: " << res_original << " Renewal Cost: " << msec << " milli sec \n";


}
