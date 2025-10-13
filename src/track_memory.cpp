#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>

// valgrind 也可以
void *operator new(size_t size)
{
    std::cout << "Allocating " << size << "\n";

    return malloc(size);
}

struct Object
{
    int x, y, z;
};

int main()
{
    std::string string = "ztq";

    std::unique_ptr<Object> obj = std::make_unique<Object>();
}