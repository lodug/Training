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
    // Note: Functions in B, C, and D are non-const.
    virtual std::string getName() { return "B"; }
};

class C: public B
{
public:
    virtual std::string getName() { return "C"; }
};

class D: public C
{
public:
    virtual std::string getName() { return "D"; }
};

int main()
{
    C c {};
    A& rBase{ c };
    std::cout << rBase.getName() << '\n';

    return 0;
}

//This one is a little trickier. rBase is an A reference to a C object, so rBase.getName() would normally call A::getName(). 
//But A::getName() is virtual, so it calls the most derived version of the function between A and C. And that is A::getName(). 
//Because B::getName() and C::getName() are not const, 
//they are not considered overrides! Consequently, this program prints A.