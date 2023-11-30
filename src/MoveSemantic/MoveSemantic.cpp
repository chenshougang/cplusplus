#include <iostream>

#include "StringContainer .h"

int csg_StringContainer();

int main() 
{
  
    csg_StringContainer();

    return 0;
}



int csg_StringContainer() 
{
    // 创建 StringContainer 对象
    StringContainer original("Hello, World!");
    original.print_address();

    // 使用移动语义进行对象间的资源转移
    StringContainer moved = std::move(original);
    moved.print_address();

    // 拷贝构造
    StringContainer deepcopy = moved;
    deepcopy.print_address();

    // 赋值构造
    StringContainer str_1("chen");
    StringContainer str_2("shou");
    str_1.print_message();
    str_2.print_message();
    str_2 = str_1;
    str_2.print_message();

    return 0;
}