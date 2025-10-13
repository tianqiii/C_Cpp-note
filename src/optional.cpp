#include <any> // 运行时类型安全
#include <fstream>
#include <iostream>
#include <optional> // 编译时类型安全
#include <string>

std::optional<std::string> ReadFile(const std::string &filepath)
{
    std::ifstream stream(filepath);
    if (stream)
    {
        std::string res;
        // read file
        stream.close();
        return res;
    }
    return {};
}

int main()
{
    std::optional<std::string> data = ReadFile("data.txt");

    std::string value = data.value_or("not present!");
    if (data.has_value())
    {
        std::cout << "file read!\n";
    }
    else
    {
        // std::string &string = *data;
        // data.value();
        std::cout << "Failed!\n";
    }

    std::any anything;
    anything = 2;
    anything = "ztq";
    anything = std::string("ztq");

    std::string string = std::any_cast<std::string>(anything);
}