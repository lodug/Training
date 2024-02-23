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
// Note: no getName() function here
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
    std::cout << rBase.getName() << '\n';

    return 0;
}

//rBase is an A reference pointing to a C object. Normally rBase.getName() would call A::getName(), but A::getName() is virtual so it instead calls the most derived matching function between A and C. 
//That is B::getName(), which prints B.