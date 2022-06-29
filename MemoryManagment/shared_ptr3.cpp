#include <iostream>
#include <memory>

void func(int* ptr) {
    std::cout << "calling DIY Deleter\n";
    delete ptr;
}

int main() {
    std::shared_ptr<int> sptr(new int(100), func);  // ()内第二参数可以自定义Deleter
}