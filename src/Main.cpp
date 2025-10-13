// #include "Log.h" // 可以自定义的 所有位置
#include <iostream> // 只能在一个绝对位置 为了区分c/c++的标准库，C的有.h后缀，cpp没有
#include <ostream>

void Log(const char *message)
{
    std::cout << message << std::endl;
}; // void 代表不返回任何东西

void Increment(int value)
{
    value++;
}

int main()
// main函数是例外，不需要返回任何值，默认返回0
{
    // Log("Hello World!");
    int a = 10;
    Increment(a);
    std::cout << a << std::endl;

    const char *string = "01234";

for (int i = 0; i < 5; i++)
    { // （开头；条件；结尾）
        const char c = string[i];
        if (i % 2 == 0)
            continue;
        std::cout << c << std::endl;
    } // {}不需要 ; 除非只有一行，可以不使用 {} 并在最后加 ;

    Log("===================================");

    int i = 0;
    while (i < 5)
    {
        Log("Hello world!");
        i++;
    }

    // do {} while(); 循环中的内容至少会被执行一次。

    // char b = 'f';
    // 如果是char类型，则 std::cout << 会输出字符，其他类型则会输出ASCII码

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    //  分割符
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    std::cout << sizeof(int) << std::endl;

    // int -> 4字节 -2^31 ~ 2^31-1
    // bool -> 1字节 true/false
    // char -> 1字节 -128 ~ 127
    // short -> 2字节 -2^15 ~ 2^15-1
    // long -> 4/8字节 历史遗留或平台差异
    // long long -> 8字节 -2^63 ~ 2^63-1
    // float -> 4字节
    // double -> 8字节
    // pointer -> 4/8字节 由系统架构决定

    // << 重载符（函数）等价于std::cout.print("H...!").print(std::endl);
    std::cout << "hello world" << std::endl;

    int  x = 5;
    bool comparisonResult = x == 5; // 存储一个布尔值，可以用作判断 实际上是二进制每一位的比较
    if (comparisonResult)
        Log("Hello World!"); // 写成两行可以在调试时候看到是在判断还是在执行代码

    const char *ptr = "Hello";
    if (ptr)
        Log(ptr);
    // else if (ptr == "Hello")
    //   Log("Ptr is hello!");
    else
        Log("Ptr is null");

    int  var = 8;
    int *pointer = &var; // 指针是一个整数，储存内存地址。
    *pointer = 10;

    int &ref = var; // "引用"，现在可以用ref代替a，像是a的一个别名
    ref = 2;
    std::cout << var << std::endl;
    // std::cin.get(); // 获取输入进行下一步操作
}
