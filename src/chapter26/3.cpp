#include <iostream>

template <typename T>
void print(const T& t)
{
    std::cout << t << '\n';
}

//let’s say we want double values (and only double values) to output in scientific notation.
void print1(double d)
{
    std::cout << std::scientific << d << '\n';
}

int main()
{
    print(5);
    print(6.7);

    //When the compiler goes to resolve print1(6.7),
    //it will see that print(double) has already been defined by us, and use that instead of instantiating a version from print(const T&).
    print1(5);
    print1(6.7);
    
    //One nice thing about defining functions this way is that the non-member function doesn’t need to have the same signature as the function template. 
    //Note that print(const T&) uses pass by const reference, whereas print(double) uses pass by value.

    return 0;
}