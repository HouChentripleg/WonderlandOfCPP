// c++14支持使用decltype(auto)实现转发函数or封装的返回类型推导
#include <iostream>

std::string func1();
std::string& func2();

// c++11的函数封装
std::string BEFORE1() {
    return func1();
}
std::string& BEFORE2() {
    return func2();
}

// c++14的函数封装
decltype(auto) AFTER1() {
    return func1();
}
decltype(auto) AFTER2() {
    return func2();
}