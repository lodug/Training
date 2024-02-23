#include <iostream>
#include <string>

class A
{
public:
    // note: no virtual keyword
    std::string getName() const { return "A"; }
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
    std::cout << rBase.getName() << '\n';

    return 0;
}

//A is not virtual, when rBase.getName() is called, A::getName() is called.