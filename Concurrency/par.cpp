#include <iostream>
#include <vector>
#include <chrono>
#include <execution>
#include <random>
#include <algorithm>

int main() {
    std::random_device rd;
    std::vector<double> vals(10000000);
    for(double& val : vals) {
        val = static_cast<double>(rd());
    }

    for(int i = 0; i < 5; i++) {
        std::vector<double> sortedVals(vals);   // 以下修改的是副本
        const auto start = std::chrono::high_resolution_clock::now();
        std::sort(sortedVals.begin(), sortedVals.end());
        const auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Latency: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    }
    return 0;
}