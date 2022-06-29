#include <iostream>
#include <functional>

int foo(int arg) {
    return arg;
}

int main() {
    // 封装普通函数
    std::function<int(int)> func1 = foo;

    // 封装lambda expression
    int x = 1;
    std::function<int(int)> func2 = [&](int val) ->int {
        return 1 + x + val;
    };

    std::cout << func1(1) << std::endl;
    std::cout << func2(1) << std::endl;
}

// std::function对函数进行封装，可看作函数的容器，比使用函数指针进行调用要更安全