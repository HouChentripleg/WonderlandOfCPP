#include <iostream>

void reference(int& val) {
    std::cout << "left value" << std::endl;
}
void reference(int&& val) {
    std::cout << "right value" << std::endl;
}

template <typename T>
void pass(T&& val) {
    std::cout << "passing value: ";
    reference(val);
}

int main() {
    std::cout << "rvalue reference" << std::endl;
    pass(1);
    std::cout << "lvalue reference" << std::endl;
    int lval = 1;
    pass(lval);

    return 0;
}

// 尽管pass(1)传递的是右值，pass()的参数val声明为右值引用，但val本身是一个左值，所以总会调用reference(int&)