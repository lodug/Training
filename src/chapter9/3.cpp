#include <iostream>

int foo(int x, int y)
{
    int z{ y };
    if (x > y)
    {
        z = x;
    }
    return z;
}

int main()
{
    std::cout << foo(1,0) << '\n';
    std::cout << foo(0,2) << '\n';

    return 0;
}