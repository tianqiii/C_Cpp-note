#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int> CreatePerson()
{
    return {"ztq", 22};
}

struct Person
{
    std::string name;
    int         age;
};

int main()
{
    // std::tuple<std::string, int> person = CreatePerson();
    // std::string                 &name = std::get<0>(person);
    // int                          age = std::get<1>(person);

    // std::string name1;
    // int         age1;
    // std::tie(name1, age1) = CreatePerson();
    const auto &[name, age] = CreatePerson();
}