#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{7, 2, 9};

    auto a = vec.begin();   // 迭代器a指向第一个元素7
    auto b = vec.end();     // 迭代器b指向最后一个元素的下一位，注意前闭后开[）
    for(auto ptr1 = a; ptr1 < b; ptr1++) {
        std::cout << *ptr1 << " ";  // Output: 7 2 9
    }
    std::cout << std::endl;

    auto c = vec.rbegin();  // 迭代器c指向最后一个元素9
    auto d = vec.rend();    // 迭代器d指向第一个元素的前一位
    for(auto ptr2 = c; ptr2 < d; ptr2++) {
        std::cout << *ptr2 << " ";  // Output: 9 2 7
    }
}