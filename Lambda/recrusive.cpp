#include <iostream>

/*
int factorial(int n) {
    return n > 1 ? n * factorial(n - 1) : 1;
}
*/

int main() {
    /*
    auto factorial = [](int n) {
        return n > 1 ? n * factorial(n - 1) : 1;
    };
    */

    auto factorial = [](int n) {
        auto f_impl = [](int n, const auto& foo) -> int {
            return n > 1 ? n * foo(n - 1, foo) : 1;
        };
        return f_impl(n, f_impl);
    };
    std::cout << factorial(5);
}

// 版本一是常规的递归函数
// 版本二试图将递归函数改成lambda，但是编译器在解析到11行时还不知道factorial这个变量的类型，而{}内又出现了factorial，就导致整个lambda表达式不能完全理解，编译失败
// 注意版本二需要显示声明lambda的返回类型-> int
// C++ Insights: f_impl的类型是外层lambda类，foo的类型是内层lambda类