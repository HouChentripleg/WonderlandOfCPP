#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string filenames[] = {"foo.txt", "yunque.png", "reborn.jpg", "AAA.txt", "What.txt", "itachi.txt"};
    std::regex pattern("[a-z]+\\.txt");
    for(const auto& file :filenames) {
        std::cout << file << ": " << std::regex_match(file, pattern) << std::endl;
    }

    return 0;
}

// [a-z]+\.txt表示匹配 纯小写字母组成的文本文件
// . 在正则表达式中表示匹配除了 \n 之外的任何单字符，为了匹配 . 本身，需要匹配 \.
// C++中 \ 会被编译器认作是转义符，为使 \. 作为正则表达式有效，需要对 \ 进行二次转义