#include <iostream>
#include <type_traits>

void foo(char*);
void foo(int);

int main() {
    // 经测试：gcc下NULL = 0，clang不是
    if(std::is_same<decltype(NULL), decltype(0)>::value) {
        std::cout << "NULL == 0" << std::endl;
    }

    return 0;
}
