#include <iostream>
#include <iterator>
#include <sstream>

int main() {
    std::istringstream str{"1 2 3 4 5"};
    std::istream_iterator<int> x(str);
    std::cout << *x << std::endl;   // 1
    ++x;    // single-pass
    std::cout << *x << std::endl;   // 2
    ++x;
    std::cout << *x << std::endl;   // 3
    return 0;
}