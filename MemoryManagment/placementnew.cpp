#include <iostream>
using namespace std;

class Bad {};

class Foo {
public:
    Foo() {
        cout << "Foo::Foo()" << endl;
    }
    Foo(int) {
        cout << "Foo::Foo(int)" << endl;
        throw Bad();
    }

    void* operator new(size_t size) {
        return malloc(size);
    }
    void* operator new(size_t size, void* start) {
        return start;
    }
    void* operator new(size_t size, long extra) {
        return malloc(size + extra);
    }
    void* operator new(size_t size, long extra, char init) {
        return malloc(size + extra);
    }
    /*
    void* operator new(long extra, size_t size) {
        return malloc(size + extra);
    }
    */

    void operator delete(void*, size_t) {
        cout << "operator delete(void*, size_t)" << endl;
    }
};

int main() {
    Foo start;
    Foo* p1 = new Foo;
    Foo* p2 = new(&start) Foo;
    Foo* p3 = new(100) Foo;
    Foo* p4 = new(100, 'a') Foo;
    // Foo* p5 = new(100) Foo(1);
}