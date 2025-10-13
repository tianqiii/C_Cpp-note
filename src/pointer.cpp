#include <iostream>
#include <ostream>

class Entity
{
private:
    int m_X, m_Y;

public:
    int GetX() const // 只有在类中的const可以这样写，表示不能改变类
    {
        return m_X;
    }

    void SetX(int x)
    {
        m_X = x;
    }
};

void PrintEntity(const Entity &e) // const代表不能修改类中的内容
{
    std::cout << e.GetX() << std::endl; // 只能调用保证不修改类内容的方法
}

int main()
{
    const int MAX_AGE = 90;

    int *const a = new int; // 常量指针，不能改变其指向
    // int const *a和const int *a是同样含义，指针常量，不能改变其指向内容。
    // const int *const a 指向常量整数的常量指针

    *a = 2;
    // a = (int *)&MAX_AGE;

    std::cout << *a << std::endl;
}