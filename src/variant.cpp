#include <cstddef>
#include <iostream>
#include <string>
#include <variant>

int main()
{
    std::variant<std::string, int, int> data;
    data = "ztq";
    if (auto *value = std::get_if<std::string>(&data))
    {
        std::string &v = *value;
    }
    else
    {
    }

    std::cout << std::get<std::string>(data) << "\n";
    data.emplace<1>(2);

    data.index();

    std::cout << std::get<1>(data) << "\n";

    data.emplace<2>(3);

    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(std::string) << "\n";
    std::cout << sizeof(size_t) << "\n";
    std::cout << sizeof(data) << "\n";
    // 本质上variant是一个类型安全的union，大小必须是最大对齐要求的倍数，这里string最大对齐是8，int为4，所以为8的倍数，增加一个int的大小不变。
}