// std::tuple_cat()合并两个元组
// std::tuple_size<>::value获取tuple长度

#include <iostream>
#include <tuple>
#include <variant>

template <size_t N, typename... Args>
constexpr std::variant<Args...> tuple_index_helper(const std::tuple<Args...>& tp, size_t i) {
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

template <typename T>
auto tupenLen(T& tp) {
    return std::tuple_size<T>::value;
}

int main() {
    auto t1 = std::make_tuple("HouChen", 1);
    auto t2 = std::make_tuple('A', 7.819);
    auto t3 = std::tuple_cat(std::move(t1), std::move(t2));

    // 遍历tuple，运行期索引
    for(int i = 0; i != tupenLen(t3); ++i) {
        std::cout << tuple_index(t3, i) << ' ';
    }
    std::cout << std::endl;
}