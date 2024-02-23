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
    C c;
    B& rBase{ c }; // note: rBase is a B this time
    std::cout << rBase.getName() << '\n';

    return 0;
}

//C::getName() is the most derived matching call between classes B and C.