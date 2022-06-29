#include <iostream>

// c++11
template <typename T, typename U>
auto add1(T x, U y) -> decltype(x+y) {
    return x + y;
}
// c++14
template <typename T, typename U>
auto add2(T x, U y) {
    return x + y;
}

int main() {
    auto res1 = add1<int, double>(7, 2.9);
    if(std::is_same<decltype(res1), double>::value) {
        std::cout << "res1 type is double" << std::endl;
    }
    std::cout << res1 << std::endl;
    std::cout << add2<int, double>(2, 7.9) << std::endl;
    
    return 0;
}

// c++20才支持使用auto实现函数形参类型推导，但从c++11开始就以及支持推导函数返回类型了
// 但c++11需要使用decltype()辅助，c++14可以单只使用auto