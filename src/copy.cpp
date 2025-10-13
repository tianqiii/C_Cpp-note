#include <cstring>
#include <iostream>
#include <ostream>
#include <stdexcept>

class String
{
private:
    char        *m_Buffer;
    unsigned int m_Size;

public:
    String(const char *string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1]; // 为终止符多分配一个字节

        // for (int i = 0; i < m_Size; i++)
        // {
        //     m_Buffer[i]= string[i];
        // }

        // 如果一个类需要自定义析构函数、拷贝构造函数或拷贝赋值运算符中的任何一个，那么它通常需要全部三个。
        memcpy(m_Buffer, string, m_Size + 1);
    }

    String(const String &other) : m_Size(other.m_Size)
    {
        std::cout << "Copied String" << std::endl;

        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char &operator[](unsigned int index) // 重载下标运算符
    {
        if (index >= m_Size)
        {
            throw std::out_of_range("Index out of Range");
        }
        return m_Buffer[index];
    }

    friend std::ostream &operator<<(std::ostream &os, const String &string);
};

std::ostream &operator<<(std::ostream &os, const String &string)
{
    os << string.m_Buffer;
    return os;
}

void PrintString(const String &string)
// 总是使用const &传递类，避免多次拷贝
{
    std::cout << string << std::endl;
}

int main()
{
    String string = "123";
    String second = string; // 两块内存储存同一个内存地址

    second[1] = '4';

    PrintString(string);
    PrintString(second);
}