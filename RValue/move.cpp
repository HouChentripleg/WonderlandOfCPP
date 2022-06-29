#include <iostream>

class A {
public:
    int *ptr;

    A() : ptr(new int(1)) {
        std::cout << "ctor" << std::endl;
    }
    A(A& a) : ptr(new int(*a.ptr)) {
        std::cout << "copy-ctor" << std::endl;
    }
    A(A&& a) : ptr(a.ptr) {
        a.ptr = nullptr;
        std::cout << "move-ctor" << std::endl;
    }
    ~A() {
        std::cout << "dtor" << std::endl;
        delete ptr;
    }
};

A return_rvalue(bool test) {
    A a, b;
    if(test) return a;  // 等价于static_cast<A&&>(a)
    else return b;      // 等价于static_cast<A&&>(b)
}

int main() {
    A obj = return_rvalue(false);
    std::cout << "obj: " << obj.ptr << std::endl;
    return 0;
}

/*
Output:
ctor
ctor
move-ctor
dtor
dtor
obj: 0xe51d80
dtor
*/

// return_rvalue()返回时，产生一个xvalue，被A的move-ctor引用，得以延长生命周期