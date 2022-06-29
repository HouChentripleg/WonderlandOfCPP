#include <iostream>
#include <string>

std::string operator"" _DIY1(const char* str, size_t len) {
    return std::string(str) + "do it by yourself!";
}

std::string operator"" _DIY2(unsigned long long i) {
    return std::to_string(i) + "do it by yourself!";
}

int main() {
    auto str1 = "HouChen"_DIY1;
    auto str2 = 729_DIY2;
    std::cout << str1 << std::endl; // HouChendo it by yourself!
    std::cout << str2 << std::endl; // 729do it by yourself!

    return 0;
}

// 标准建议重载operator""的函数名前最后加有前缀_