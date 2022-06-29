#include <iostream>
#include <new>
#include <memory>

void func(int* ptr) {
    std::cout << "func DIY Deleter called\n";
    delete ptr;
}

int main() {
    std::unique_ptr<int, decltype(&func)> x(new int(100), func);
}