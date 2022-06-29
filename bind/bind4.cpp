#include <iostream>
#include <functional>

void MyProcess(int& x) {
    ++x;
}

int main() {
    int x = 0;
    auto a = std::bind(MyProcess, x);
    a();
    std::cout << x; // 输出0

    int y = 0;
    auto b = std::bind(MyProcess, std::ref(y));
    b();
    std::cout << y; // 输出1

    return 0;
}