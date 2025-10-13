#include <cstdio>
#include <iostream>

template <typename T> void Print(T value)
{ // 只有被调用的时候才会创建
    std::cout << value << std::endl;
}

int main()
{
    Print<int>(5);
    Print<std::string>("Hello");
    Print<double>(5.5f);
}