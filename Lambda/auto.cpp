#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, int> umap{{2, 3}};
    /*
    auto lambda = [](const std::pair<int, int>& umap) {
        return umap.first + umap.second;
    };
    */
    auto lambda = [](const auto& umap) {
        return umap.first + umap.second;
    };
    std::cout << lambda(*umap.begin());
}

// 虽然版本一看起来是引用传递，避免了复制，但实际上umap的value_type是std::pair<const Key, T>，类型不同，还是存在复制
// C++14对lambda引入auto后就能彻底避免复制