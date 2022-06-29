#include <iostream>

template <typename T>
void func(T input) {
    std::cout << input << std::endl;
}

/*
void normalFunc() {
}
*/

// 模板函数可以在多文件中重复引入头文件，普通函数不可