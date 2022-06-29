#include <iostream>

// 递归模板函数：必须写递归终止条件
template <typename T>
void print(const T& val) {
    std::cout << val << std::endl;
}
template <typename firstArg, typename... Args>
void print(const firstArg& first, const Args&... args) {
    std::cout << first << std::endl;
    if constexpr(sizeof...(args) > 0) print(args...);
}

// initializer_list + lambda expression黑魔法版本
template <typename firstArg, typename... Args>
auto printf(const firstArg& first, const Args&... args) {
    std::cout << first << std::endl;
    std::initializer_list<firstArg>{(
        [&args]{
            std::cout << args << std::endl;
        }(), first)...};
}

int main() {
    print(1, 5.7, "hello");

    printf(5, 7.9, "world");

    return 0;
}

// 使用initializer_list，(lambda expression, first)...将会被展开
// 先执行lambda expression输出参数