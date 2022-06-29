#include <iostream>

struct Str {
    auto func() {
        int val = 2;
        auto lambda = [val, *this]() {
            return val > x;
        };
    }
    int x;
};

auto wrapper() {
    Str s;
    return s.func();
}

int main() {
    wrapper();
}

// Str类型的对象s是一个局部自动对象，当离开wrapper()作用域后被销毁了，如果func()中的lambda捕获的是this，就会丢失资源、徒留悬挂指针
// 所以捕获*this，虽然是复制，但安全