#include <iostream>
#include <string>

class Base1
{
public:
    std::string getName() const { return "Base1"; }
};

class Derived1: public Base1
{
public:
    std::string getName() const { return "Derived1"; }
};


class Base
{
public:
    virtual std::string getName() const { return "Base"; } // note addition of virtual keyword
};

class Derived: public Base
{
public:
    virtual std::string getName() const { return "Derived"; }
};


int main()
{
    Derived1 derived1 {};

    Base1& rBase1{ derived1 };
    std::cout << "rBase1 is a " << rBase1.getName() << '\n';

    Derived derived {};

    Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}

//Because rBase1 is a Base1 reference, it calls Base1::getName(), even though it’s actually referencing the Base1 portion of a Derived1 object.
// this issue can be solved by using virtual functions: A virtual function is a special type of member function that, when called, 
// resolves to the most-derived version of the function for the actual type of the object being referenced or pointed to.

//A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) 
//and return type as the base version of the function. 
//Such functions are called overrides.

//Because rBase is a reference to the Base portion of a Derived object, when rBase.getName() is evaluated, 
//it would normally resolve to Base::getName(). However, Base::getName() is virtual, 
//which tells the program to go look and see if there are any more-derived versions of the function available for a Derived object. 
//In this case, it will resolve to Derived::getName()!

