#include <iostream>

int main()
{
    int x{ 1 };
    int& ref{ x };

    std::cout << x << ref << '\n';

    int y{ 2 };
    ref = y;
    y = 3;

    std::cout << x << ref << '\n';

    x = 4;

    std::cout << x << ref << '\n';

    ref = 5;
    std::cout << x << ref << '\n';

    y = 7;
    std::cout << x << ref << '\n';
    
    return 0;
}