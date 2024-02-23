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
    // note: no virtual keyword in B, C, and D
    std::string getName() const { return "B"; }
};

class C: public B
{
public:
    std::string getName() const { return "C"; }
};

class D: public C
{
public:
    std::string getName() const { return "D"; }
};

int main()
{
    C c {};
    B& rBase{ c }; // note: rBase is a B this time
    std::cout << rBase.getName() << '\n';

    return 0;
}

//Even though B and C aren’t marked as virtual functions, A::getName() is virtual and B::getName() and C::getName() are overrides. 
//Therefore, B::getName() and C::getName() are considered implicitly virtual, and thus the call to rBase.getName() resolves to C::getName(), 
//not B::getName().