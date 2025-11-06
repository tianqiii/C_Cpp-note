#include <iostream>
using namespace std;

int multiply(int a, int b)
{
    int result = a * b;
    return result;
}

int MultiplyAndLog(int a, int b)
{
    int result = a * b;
    std::cout << result << std::endl;
    return result;
}

int main()
{
    // int num1, num2;
    // std::cout << "input first integer: ";
    // std::cin >> num1;

    // std::cout << "input second integer: ";
    // std::cin >> num2;

    // int res = multiply(num1, num2);
    // std::cout << "result:" << res << std::endl;
    MultiplyAndLog(3, 2);
    MultiplyAndLog(8, 5);
    MultiplyAndLog(10, 5);

    // std::cin.get();
}
