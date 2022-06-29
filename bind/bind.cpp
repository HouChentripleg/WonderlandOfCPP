#include <iostream>
#include <functional>

void foo(int a, int b, double c) {
    std::cout << a << " " << b << " " << c << " " << std::endl;
}

int main() {
    auto func = std::bind(foo, std::placeholders::_1, 1, 5.5);
    func(5);
}

// std::bind是function wrapper，用于绑定函数的参数
// 当无法一次性获取函数的全部参数but可以将部分参数提前绑定到函数上生成一个新的对象时，之后参数到齐就可以实现调用