// c++17支持if constexpr关键字，可以在编译期间就完成分支判断
#include <iostream>

template <typename T>
auto func(const T& t) {
    if constexpr(std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}

int main() {
    std::cout << func(5) << std::endl;
    std::cout << func(5.5) << std::endl;
}