#include <iostream>
#include <array>
#include <type_traits>

void func(int *ptr) {}

int main() {
    /* 普通数组不支持复制
    int a[3] = {1, 2, 3};
    int b[3] = a;   // 报错
    */
    std::array<int, 3> a1{1, 2, 3}; // ctor:累积初始化，注意缺省情况下是乱值
    std::array<int, 3> a2;
    std::array<int, 3> a3{5, 6, 7};
    a2 = a1;    // array支持复制

    std::cout << a1[100];   // 数组越界，输出乱值
    std::cout << a1.at(100);// 数组越界，程序crash，很nice的提醒
    std::cout << std::is_same_v<std::array<int, 3>::value_type, int>;   //  Output: 1
    func(a1.data());    // a1.data()返回指向第一个元素的指针，可以用于函数调用
    a1.swap(a3);        // 交换a1和a3的值
    for(int num : a1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}