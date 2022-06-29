#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <ratio>
#include <algorithm>
#include <execution>

int main() {
    std::random_device rd;
    std::vector<double> vals(10000000);
    for(double& val : vals) {
        val = static_cast<double>(rd());
    }

    for(int i = 0; i < 5; i++) {
        std::vector<double> sortedVals(vals);   // 以下修改的是副本
        const auto start = std::chrono::high_resolution_clock::now();
        std::sort(std::execution::par, sortedVals.begin(), sortedVals.end());
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Latency: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    }
    return 0;
}

// 需要最低GCC 9.1 version和TBB库
// g++ -par.cpp -o par -std=c++17 -O3 -ltbb
// 默认的std::execution::seq平均排序时间是1800ms，std::execution::par平均排序时间是600ms