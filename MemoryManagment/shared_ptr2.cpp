#include <iostream>
#include <new>
#include <memory>

int main() {
    auto x = std::make_shared<int>(100);
    std::cout << *x << std::endl;   // 对shared_ptr解引用，输出100
    std::cout << *(x.get()) << std::endl;   // get()返回int*，对int*解引用，输出100

    auto y = x;
    std::cout << x.use_count() << std::endl; // 2
    y.reset();
    std::cout << x.use_count() << std::endl; // 1
    
    auto z = x;
    x.reset(new int(50)); // x指向新内存，z保持不变
    std::cout << *x << std::endl; // 50
    std::cout << *z << std::endl; // 100
    std::cout << x.use_count() << std::endl; // 1
    std::cout << z.use_count() << std::endl; // 1
}