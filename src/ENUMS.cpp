#include <iostream>

int a = 0; // 数据没有分组
int b = 1;
int c = 2;

enum Example : unsigned char // 这里只能用整型，不能用 float
{
    A = 0,
    B = 3,
    C = 6
};

int main()
{
    Example value = B;

    if (value == B)
    {
    }
}
