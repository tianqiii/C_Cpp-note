#include <iostream>

int &GetValue()
{
    static int value = 10; // 没有static会导致函数结束变量销毁
    return value;
}

int main()
{
    GetValue() = 5;
    int  a = GetValue();
    int &ref = GetValue();
    GetValue() = 10;

    std::cout << a << " " << ref << "\n";
}