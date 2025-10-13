#include <functional>
#include <iostream>
#include <vector>

// using namespace std; 可以用在某个作用域内。

void Hello(int v)
{
    std::cout << "hello!" << "v" << std::endl;
}

void ForEach(const std::vector<int> &values, const std::function<void(int)> &func)
{
    for (int value : values) // -based for 循环，":"的意思相当于in
    {
        func(value);
    }
}

int main()
{
    auto function = Hello; // 去掉括号获取函数地址
    void (*func)(int) = Hello;

    typedef void (*HelloFunc)(int);
    HelloFunc fc = Hello;

    std::vector<int> values = {1, 2, 3, 4, 5};

    // function();
    // func();
    // fc();

    int a = 5;

    ForEach(values, Hello);
    ForEach(values, [=](int value) { std::cout << value << a << std::endl; });

    // 只能绑定到非常量引用，可以临时对象的生命周期到作用域结束。
    //
    //  []是“捕获方法”
    //  = 传递所有变量
    //  & 通过引用传递所有变量
    //  可以通过变量名或引用变量名来单独传递某个变量
    //
    //  这是lambda函数（匿名函数），一次性使用的函数，定义如何输入输出。将其视为变量
}