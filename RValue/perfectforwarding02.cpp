#include <iostream>
#include <utility>

void reference(int& val) {
    std::cout << "left value" << std::endl;
}
void reference(int&& val) {
    std::cout << "right value" << std::endl;
}

template <typename T>
void pass(T&& val) {
    std::cout << "passing normal value: ";
    reference(val);
    std::cout << "passing std::move(value): ";
    reference(std::move(val));
    std::cout << "passing std::forward<T>(value): ";
    reference(std::forward<T>(val));
    std::cout << "passing static_cast<T&&>(value): ";
    reference(static_cast<T&&>(val));
}

int main() {
    std::cout << "rvalue reference" << std::endl;
    pass(1);
    std::cout << "lvalue reference" << std::endl;
    int lval = 1;
    pass(lval);

    return 0;
}

// perfect forwarding: 参数传递时能保持原来的参数类型
// 左引用保持左引用，右引用保持右引用
// std::forward<T>(val)与static_cast<T&&>(val)完全等价

/*
Output:
rvalue reference
passing normal value: left value
passing std::move(value): right value
passing std::forward<T>(value): right value
passing static_cast<T&&>(value): right value
lvalue reference
passing normal value: left value
passing std::move(value): right value
passing std::forward<T>(value): left value
passing static_cast<T&&>(value): left value
*/