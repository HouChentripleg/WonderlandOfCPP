#include <iostream>

int main() {
    auto x = 1;
    auto y = 2;
    decltype(x + y) z;

    if(std::is_same<decltype(z), int>::value) {
        std::cout << "type z == int" << std::endl;
    }

    return 0;
}