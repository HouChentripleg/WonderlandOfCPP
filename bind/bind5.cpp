#include <iostream>
#include <functional>
#include <algorithm>

int MyMax(int a, int b, int c) {
    std::cout << "finding the maximum...\n";
    return std::max({a, b, c});
}

int main() {
    auto x = std::bind_front(MyMax, 1); // 输出9
    std::cout << x(5, 9);

    auto y = std::bind_back(MyMax, 10); // 输出10
    std::cout << y(5, 9);

    return 0;
}

