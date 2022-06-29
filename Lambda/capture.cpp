#include <iostream>
#include <memory>
#include <utility>

int main() {
    auto uptr = std::make_unique<int>(1);   // unique_ptr型智能指针, 将其转成右值再捕获
    auto add = [v1 = 1, v2 = std::move(uptr)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << std::endl;
}

// c++14以后允许lambda的capture list中的成员用任意表达式进行初始化，也就是支持左值/右值捕获