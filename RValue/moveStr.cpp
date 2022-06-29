#include <iostream>
#include <utility>
#include <string>
#include <vector>

int main() {
    std::string str = "hello, move sematics";
    std::vector<std::string> vec;

    // 调用的是push_back(const T&)，产生拷贝行为
    vec.push_back(str);
    std::cout << str << std::endl;

    // 调用的是push_back(const T&&)
    vec.push_back(std::move(str));
    std::cout << str << std::endl;  // move后str为空

    return 0;
}