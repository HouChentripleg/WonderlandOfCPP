#include <iostream>
#include <new>
#include <memory>

struct Str
{
    // std::shared_ptr<Str> ptr;
    std::weak_ptr<Str> ptr;
    ~Str() {
        std::cout << "~Str() is called\n";
    }
};

int main() {
    auto x(std::make_shared<Str>());
    auto y(std::make_shared<Str>());
    
    x->ptr = y;
    y->ptr = x;
}

// Str内使用shared_ptr：作用域内x, y的引用计数==2，离开main作用域时调用shared_ptr的dtor将引用计数-1，但还有1，造成内存泄漏
