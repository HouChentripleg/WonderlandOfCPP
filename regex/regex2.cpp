#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string filenames[] = {"foo.txt", "yunque.png", "reborn.jpg", "AAA.txt", "What.txt", "itachi.txt"};
    std::regex pattern("([a-z]+)\\.txt");
    std::smatch smatch;
    for(const auto& file : filenames) {
        if(std::regex_match(file, smatch, pattern)) {
            if(smatch.size() == 2) {
                std::string base = smatch[1].str();
                std::cout << "sub-match[0]: " << smatch[0].str() << std::endl;
                std::cout << file << " sub-match[1]: " << base << std::endl;
            }
        }
    }

    return 0;
}

// std::smatch的第一个元素匹配整个字符串
// std::smatch的第二个元素匹配第一个()表达式

/*

Output:
sub-match[0]: foo.txt
foo.txt sub-match[1]: foo      
sub-match[0]: itachi.txt       
itachi.txt sub-match[1]: itachi

*/