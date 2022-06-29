#include <iostream>

int main() {
    auto add = [](auto x, auto y) {
        return x + y;
    };
    std::cout << add(3, 4) << std::endl;
    std::cout << add(3.5, 4.5) << std::endl;
}

// c++14后允许参数列表用auto实现泛化