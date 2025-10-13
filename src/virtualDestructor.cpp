#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Constructor\n";
    }
    virtual ~Base()
    {
        std::cout << "Destructor\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived Constructor\n";
    }
    ~Derived()
    {
        std::cout << "Derived Destructor\n";
    }
};

int main()
{
    // Base *base = new Base();
    // delete base;
    // std::cout << "<<<<<<<<<<<<<<<<<<\n";
    Derived *derived = new Derived();
    delete derived;
    // std::cout << "<<<<<<<<<<<<<<<<<<\n";
    // Base *poly = new Derived();
    // delete poly;

    double value = 5.25;
    double a = (int)value + 5.3; // C风格类型转换

    double s = static_cast<int>(value) + 5.3; // C++风格字符转换，可供查找，增加了编译时检查

    Derived *c = reinterpret_cast<Derived *>(&value);

    // dynamic_cast<type>() 用于多态类型 父类需要有个虚函数声明继承的多态
}