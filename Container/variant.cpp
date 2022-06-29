// tuple的std::get<>()依赖编译时期的常量，无法实现允许时索引
// c++17引入std::variant这个类模板，可以辅助tuple实现允许期索引
#include <iostream>
#include <tuple>
#include <variant>

template <size_t N, typename... Args>
constexpr std::variant<Args...> tuple_index_helper(const std::tuple<Args...>& tp, size_t i) {
    std::cout << N << std::endl;
    std::cout << sizeof...(Args) << std::endl;
    if constexpr(N >= sizeof...(Args))
        throw std::out_of_range("out of range!");
    if(i == N)
        return std::variant<Args...> { std::in_place_index<N>, std::get<N>(tp) };   // 语法见cppreference: std::variant ctor No.7
    return tuple_index_helper<(N < sizeof...(Args) - 1 ? N + 1 : 0)>(tp, i);    // 递归
}

template <typename... Args>
constexpr std::variant<Args...> tuple_index(const std::tuple<Args...>& tp, size_t i) {
    return tuple_index_helper<0>(tp, i);    // N == 0
}

template <typename First, typename... Args>
std::ostream& operator<<(std::ostream& stream, std::variant<First, Args...> const& variant) {
    std::visit([&](auto&& x) { stream << x; }, variant);
    return stream;
}

int main() {
    auto t = std::make_tuple('a', "hello tuple", 7819, 5.4);
    int index = 1;
    // std::cout << std::get<index>(t) << std::endl;   // 非法，std::get<>必须是常量
    std::cout << tuple_index(t, index) << std::endl;    // 通过tuple_index()实现运行期的索引
}