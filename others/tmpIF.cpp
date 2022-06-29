#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    // before c++17
    const auto iter1 = std::find(vec.begin(), vec.end(), 2);
    if(iter1 != vec.end()) {
        *iter1 = 7;     // 迭代器是const，指向的变量非const，可变
    }

    // after c++17
    if(const auto iter2 = std::find(vec.begin(), vec.end(), 3);
        iter2 != vec.end()) {
            *iter2 = 9;
    }
    
    for(auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
}

// c++17后允许在if()和switch()语句中声明临时变量