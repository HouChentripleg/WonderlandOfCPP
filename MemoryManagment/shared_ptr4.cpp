#include <iostream>
#include <new>
#include <array>
#include <memory>

int main() {
    std::shared_ptr<int[]> x(new int[4]{1, 2, 3, 4});
    std::cout << x[0] << x[3] << std::endl;

    auto y = std::make_shared<int[]>(4);
    y[0] = 9;
    y[1] = 8;
    y[2] = 3;
    y[3] = 10;
    std::cout << y[0] << y[3] << std::endl;

    return 0;
}