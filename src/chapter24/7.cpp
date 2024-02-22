#include <iostream>

class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
};

class B: public A
{
public:
    B(int a, double b)
    : A{ a }
    {
        std::cout << "B: " << b << '\n';
    }
};

class C: public B
{
public:
    C(int a, double b, char c)
    : B{ a, b }
    {
        std::cout << "C: " << c << '\n';
    }
};

int main()
{
    C c{ 5, 4.3, 'R' }; //First, main() calls C(int, double, char). The C constructor calls B(int, double). The B constructor calls A(int). 
    // Because A does not inherit from anybody, this is the first class we’ll construct. 
    // A is constructed, prints the value 5, and returns control to B. B is constructed, prints the value 4.3, 
    // and returns control to C. C is constructed, prints the value ‘R’, and returns control to main(). 
    //It is worth mentioning that constructors can only call constructors from their immediate parent/base class. 
    //Consequently, the C constructor could not call or pass parameters to the A constructor directly. 
    //The C constructor can only call the B constructor (which has the responsibility of calling the A constructor).

    B b{ 5, 4.3};

    return 0;
}