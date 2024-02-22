#include <iostream>

class Base
{
private:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

protected:
    void printValue() const { std::cout << m_value; }
};

//Because Base::printValue() has been declared as protected, it can only be called by Base or its derived classes. The public can not access it.
//Let’s define a Derived class that changes the access specifier of printValue() to public:

class Derived: public Base
{
public:
    Derived(int value)
        : Base { value }
    {
    }

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printValue; // note: no parenthesis here
};

int main()
{
    Derived derived { 7 };

    // printValue is public in Derived, so this is okay
    derived.printValue(); // prints 7
    return 0;
}

//You can only change the access specifiers of base members the derived class would normally be able to access. 
//Therefore, you can never change the access specifier of a base member from private to protected or public, 
//because derived classes do not have access to private members of the base class.