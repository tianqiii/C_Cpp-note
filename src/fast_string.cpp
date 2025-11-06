#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

static uint32_t s_AllocCount = 0;

#define STRING_VIEW 1

void *operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "allocating " << size << " bytes\n";
    return malloc(size);
}
#if STRING_VIEW
void PrintName(std::string_view name)
{
    std::cout << name << "\n";
}
#else
void PrintName(const std::string &name)
{
    std::cout << name << "\n";
}
#endif

int main()
{
    std::string *name = new std::string("z tq");
    // std::string  name = "z tq";
    // const char *name = "z tq";
    // 也可以用name[]

#if STRING_VIEW
    std::string_view familyName((*name).c_str(), 1);
    std::string_view givenName((*name).c_str() + 2, 2);
#else
    std::string familyName = (*name).substr(0, 1);
    std::string givenName = (*name).substr(2, 2);
#endif
    PrintName(*name);
    PrintName(familyName);
    PrintName(givenName);

    std::cout << s_AllocCount << "\n";
}