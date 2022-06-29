#include <iostream>
#include <utility>
#include <string>

void reference(std::string& str) {
    std::cout << "left value" << std::endl;
}
void reference(std::string&& str) {
    std::cout << "right value" << std::endl;
}

int main() {
    std::string lv1 = "hello, ";
    // std::string&& rv1 = lv1; // 非法，右值引用不能引用左值
    std::string&& rv1 = std::move(lv1); // std::move()将左值转为右值，右值引用延长了lv1的生命周期
    std::cout << rv1 << std::endl;  // rv1本身是左值，但它引用了右值

    // std::string& lv2 = lv1 + lv1;    // 非法：非常量引用的初始值必须为左值，注意此时lv1已是右值
    const std::string& lv2 = lv1 + lv1; // 常量左值引用：延长临时变量的生命周期
    std::cout << lv2 << std::endl;

    std::string&& rv2 = lv1 + lv2; // 右值引用
    std::cout << rv2 << std::endl;
    
    reference(rv2); // rv2虽然引用了右值，但它自己本身是一个左值，这会给参数转发带来问题

    return 0;
}

// 非常量引用无法绑定右值：数据的修改是对右值这个临时对象的，但左值本身没有被修改，存在逻辑错误
// 常量引用允许绑定右值：Fortran需要