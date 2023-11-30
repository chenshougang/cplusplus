// cplusplus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
// #include <format>

//import <iostream>;

enum class PieceType
{
    King = 1,
    Queen,
    Rook,
    Pawn
};

class csg
{
public:
    static void print()
    {
        std::cout << "csg print" << std::endl;
    }

private:
    static void print_new()
    {
        std::cout << "csg print_new" << std::endl;
    }
};


class shape
{
public:
    shape() {};
    ~shape() {};
    void print_shape()
    {
        std::cout << "print_shape" << std::endl;
    }
};

class circle :public shape
{
public:
    circle() {};
    ~circle() {};
    void print_circle()
    {
        std::cout << "print_circle" << std::endl;
    }
};

int main() 
{
    std::cout << "Hello World!\n";

    // std::cout << std::format("xxxx") << std::endl;

    std::cout << "max int value = " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "min int value = " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "lowest int value = " << std::numeric_limits<int>::lowest() << std::endl;


    std::cout << "max double value = " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "min double value = " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "lowest double value = " << std::numeric_limits<double>::lowest() << std::endl;

    std::cout << "__func__ = " << __func__ << std::endl;

    int i = 10;
    int* p = &i;

    std::cout << &i << std::endl;
    *p = 11;
    std::cout << p << std::endl;
    std::cout << i << std::endl;

    csg::print();

    circle csg_circle;
    csg_circle.print_shape();
    csg_circle.print_circle();

    // std::cout << __has_cpp_attribute(__fallthrough) << std::endl;

    std::cout << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
