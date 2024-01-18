#include <iostream>

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
}

int main()
{
    const int x { 3 };           // x is a compile time constant

    const int y { getNumber() }; // y is a runtime constant

    const int z { x + y };       // x + y is a runtime expression, so z is a runtime const

    return 0;
}