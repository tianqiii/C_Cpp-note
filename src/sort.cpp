#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

struct Entity
{
    int x, y;
};

int main()
{
    std::vector<int> values = {1, 5, 4, 1, 2};
    std::sort(values.begin(), values.end(), // 比较器
              [](int a, int b)
              {
                  if (a == 1)
                      return false;
                  if (b == 1)
                      return true;
                  return a < b;
              }); // 可以自定义排序方法 std::greater<int>()

    // for (int value : values)
    // {
    //     std::cout << value << std::endl;
    // }

    // >>>>>>类型转换<<<<<<<类型双关

    int    a = 100;
    double value = *(double *)&a; // 内存地址变成指针，再解引用变成double类型
    std::cout << value << std::endl;

    Entity e = {16, 8};

    int *pos = (int *)&e;

    int y = *(int *)((char *)&e + 4); // 直接操作内存访问第二个值

    std::cout << pos[0] << "," << pos[1] << "," << y << std::endl;

    std::cin.get();
}