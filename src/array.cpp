#include <array>
#include <iostream>

int main()
{
    int example[5]; // 实际上是一个指针
    int count = sizeof(example) / sizeof(int);

    // example[-1] 这种会导致内存冲突，确保一定在数组的边界内操作。

    for (int i = 0; i < 5; i++)
        example[i] = 2;

    int *ptr = example;
    example[2] = 5;
    *(ptr + 2) = 6; // 访问指针+2*4位的地址并修改 (sizeof(int) = 4)

    // int *another = new int[5]; // new分配的内存会一直存在，直到用delete[]删除

    std::array<int, 5> another;
    // c++11内置数据结构，会检查数组的大小 更安全但是每次都会额外存储一个size

    for (int i = 0; i < another.size(); i++)

        another[i] = 2;
    // delete[] another;

    for (int i = 0; i < 5; i++)
    {
        std::cout << example[i] << "," << count << std::endl;
    } // std::cout << example << std::endl;
}
