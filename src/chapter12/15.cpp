#include <iostream>

int main()
{
    int x{ 5 };
    int* const ptr { &x }; // ptr will always point to x
    //ptr = &y; // error: once initialized, a const pointer can not be changed.
    *ptr = 6; // okay: the value being pointed to is non-const

    std::cout << *ptr << '\n'; 
    std::cout << x << '\n'; 
    std::cout << &ptr << '\n';

    return 0;
}