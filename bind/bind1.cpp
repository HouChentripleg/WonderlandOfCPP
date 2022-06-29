#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main() {
    std::vector<int> x{1, 2, 3, 4, 5, 6};
    std::vector<int> y;
    // std::copy_if(x.begin(), x.end(), std::back_inserter(y), std::bind1st(std::greater<int>(), 3));  // 绑定std::greater()的第一个参数为3，输出1 2
    std::copy_if(x.begin(), x.end(), std::back_inserter(y), std::bind2nd(std::greater<int>(), 3));  // 绑定std::greater()的第二个参数为3，输出 4 5 6
    for(int num : y) {
        std::cout << num << ' ';
    }
    std::cout << "\n";
    return 0;
}

// std::greater()的实现
/*
constexpr bool operator()(const T &lhs, const T &rhs) const {
    return lhs > rhs;
}
*/
