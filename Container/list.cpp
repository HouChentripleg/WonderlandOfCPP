#include <iostream>
#include <list>

// 重载<<符号 
std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
    for (const auto &i : list) {
        ostr << ' ' << i;
    }
    return ostr;
}
 
int main()
{
    std::list<int> list1 = { 5,9,1,3,3 };
    std::list<int> list2 = { 8,7,2,3,4,4 };
 
    list1.sort();
    list2.sort();
    std::cout << "list1:  " << list1 << '\n';
    std::cout << "list2:  " << list2 << '\n';
    list1.merge(list2);
    std::cout << "merged: " << list1 << '\n';

    std::list<int> list3 = { 1, 2, 3, 4, 5 };
    std::list<int> list4 = { 10, 20, 30, 40, 50 };
 
    auto it = list3.begin();
    std::advance(it, 2);    // it指向元素"3"
 
    list3.splice(it, list4);    // 把list4的元素移动到it处
 
    std::cout << "list3: " << list3 << "\n";
    std::cout << "list4: " << list4 << "\n";
 
    list4.splice(list4.begin(), list3, it, list3.end());
 
    std::cout << "list3: " << list3 << "\n";
    std::cout << "list4: " << list4 << "\n";

    list4.reverse();
    std::cout << "list4 reversed: " << list4 << "\n";
}