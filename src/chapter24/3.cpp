#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A\n";
    }
};

class B: public A
{
public:
    B()
    {
        std::cout << "B\n";
    }
};

class C: public B
{
public:
    C()
    {
        std::cout << "C\n";
    }
};

class D: public C
{
public:
    D()
    {
        std::cout << "D\n";
    }
};

int main()
{
    std::cout << "Instantiating A\n";
    A a;

    std::cout << "Instantiating B\n";
    B b;

    std::cout << "Instantiating C\n";
    C c;

    std::cout << "Instantiating D\n";
    D d;
    //C++ constructs derived classes in phases, starting with the most-base class (at the top of the inheritance tree) and 
    //finishing with the most-child class (at the bottom of the inheritance tree). 
    //As each class is constructed, the appropriate constructor from that class is called to initialize that part of the class.
    
    return 0;
}