#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <numeric>

int main() {
    std::istringstream str{"1 2 3 4 5"};
    std::istream_iterator<int> x(str);
    std::istream_iterator<int> y{}; // 缺省版迭代器，注意写成()是声明函数
    int res = std::accumulate(x, y, 0);
    std::cout << res << std::endl;
    return 0;
}