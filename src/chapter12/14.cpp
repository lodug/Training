#include <iostream>

int main()
{
    int x { 5 };
    int* ptr { &x }; // ptr is a normal (non-const) pointer
    std::cout << *ptr << '\n'; 
    std::cout << &ptr << '\n'; 

    int y { 6 };
    ptr = &y; // we can point at another value
    std::cout << *ptr << '\n'; 
    std::cout << &ptr << '\n'; 

    *ptr = 7; // we can change the value at the address being held
   
    std::cout << *ptr << '\n'; 
    std::cout << y << '\n'; 
    std::cout << &ptr << '\n'; 


    return 0;
}