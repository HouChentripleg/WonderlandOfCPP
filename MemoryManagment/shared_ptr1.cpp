#include <iostream>
#include <new>
#include <memory>

int main() {
    std::shared_ptr<int> x(new int(3));
    auto y = std::make_shared<int>(x);  // 推荐使用
    std::cout << x.use_count() << std::endl; 
}
// 离开作用域时先销毁y，引用计数-1，再销毁x，引用计数-1为0，调用shared_ptr的dtor释放对象在堆上的内存块