#include <iostream>
#include <string>

class A
{
public:
    virtual std::string getName() const { return "A"; }
};

class B: public A
{
public:
    virtual std::string getName() const { return "B"; }
};

class C: public B
{
public:
    virtual std::string getName() const { return "C"; }
};

class D: public C
{
public:
    virtual std::string getName() const { return "D"; }
};

int main()
{
    C c {};
    A& rBase{ c };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}

//First, we instantiate a C class object. 
//rBase is an A reference, which we set to reference the A portion of the C object. 
//Finally, we call rBase.getName(). rBase.getName() evaluates to A::getName(). However, A::getName() is virtual, 
//so the compiler will call the most-derived match between A and C. In this case, that is C::getName(). Note that it will not call D::getName(), 
//because our original object was a C, not a D, so only functions between A and C are considered.
//Note that virtual function resolution only works when a virtual member function is called through a pointer or reference to a class type object. 
//This works because the compiler can differentiate the type of the pointer or reference from the type of the object being pointed to or referenced. 
//we see this in example above.