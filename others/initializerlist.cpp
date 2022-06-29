#include <iostream>
#include <initializer_list>
#include <vector>

class Foo {
public:
    std::vector<int> vec;

    // 初始化列表构造函数
    Foo(std::initializer_list<int> list) {  
        for(auto iter = list.begin(); iter != list.end(); ++iter) {
            vec.push_back(*iter);
        }
    }

    // 初始化列表普通函数
    void func(std::initializer_list<int> list) {
        for(auto iter = list.begin(); iter != list.end(); ++iter) {
            vec.push_back(*iter);
        }
    }
};

int main() {
    Foo foo{1, 2, 3, 4};
    for(auto it = foo.vec.begin(); it != foo.vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    foo.func({5, 6, 7});
    for(auto it = foo.vec.begin(); it != foo.vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
}