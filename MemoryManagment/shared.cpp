#include <iostream>
#include <new>
#include <memory>

struct Str
{
    std::weak_ptr<Str> ptr;
    ~Str() {
    std::cout << "~Str() is called\n";
    }
};


int main() {
    std::shared_ptr<Str> x(new Str{}); 
    {
        std::shared_ptr<Str> y(new Str{}); 
        x->ptr = y; 
        y->ptr = x;
    }

    if(auto p = x->ptr.lock()) {
        std::cout << "can access pointer\n";
    } else {
        std::cout << "cannot access pointer\n";
    }
}