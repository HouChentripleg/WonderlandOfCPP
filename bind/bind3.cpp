#include <iostream>
#include <functional>

bool MyPredit(int val1, int val2) {
    return val1 > val2;
}

bool MyAnd(int val1, int val2) {
    return val1 && val2;
}

int main() {
    using namespace std::placeholders;
    auto x = std::bind(MyPredit, _1, 3);
    std::cout << x(5);  // 输出1

    auto y = std::bind(MyPredit, 3, _1);
    std::cout << y(5);  // 输出0

    auto z = std::bind(MyPredit, _2, _1);
    std::cout << z(10, 5);  // 输出0

    auto q = std::bind(MyPredit, _3, _2);
    std::cout << q("hello", 10, 5);  // 输出0

    auto a1 = std::bind(MyPredit, _1, 2);   // a1>2才返回1
    auto a2 = std::bind(MyPredit, 9, _1);   // a2<9才返回1
    auto a3 = std::bind(MyAnd, a1, a2);     // a1和a2均为1才返回1
    std::cout << a3(7) << std::endl;    // 输出1
}

// MyPredit是callable object，_1是调用x时的第一个参数，即5，且5是MyPredict的第一个参数，3是MyPredict的第二个参数
// 对于y，3是MyPredict的第一个参数，_1对应的5是MyPredict的第二个参数
// 对于z，10是MyPredict的第二个参数，5是MyPredict的第一个参数
// 对于q，_1对应"hello"，此处并没有被传入MyPredict