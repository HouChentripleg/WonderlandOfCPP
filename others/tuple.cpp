#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> func() {
    return {1, 7.29, "hello, tuple"};
}

int main() {
    auto [x, y, z] = func();
    std::cout << x << ", " << y << ", " << z << std::endl;

    return 0;
}

// c++11/14的tuple可以作为函数的返回值，返回多个值，但是并不能直接从返回的tuple中拿到并定义tuple中的元素
// c++17可以支持：结构化绑定structured bindings