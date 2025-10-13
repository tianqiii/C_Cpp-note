#include <array>
#include <cstddef>
#include <iostream>

// #define PI 3.14 → 常量宏

// #define SQUARE(x) ((x) * (x)) → 函数宏

// #ifdef #ifndef #endif → 条件编译

// #/## → 字符串化、拼接

// void PrintArray(const std::array<int, 5> &array)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << array[i] << std::endl;
//     }
// }

template <typename T, size_t s> void Print(const std::array<T, s>(&arr))
// 不传递数组的大小 打印数组
{
    for (size_t i = 0; i < s; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 5> data;
    // data.size();
    data[0] = 2;
    data[4] = 1;
    Print(data);

    std::array<int, 5> dataOld;
    dataOld[0] = 0;
}