#include <iostream>
#include <string>

class Base
{
public:
    std::string getName() const { return "Base"; }
};

class Derived: public Base
{
public:
    std::string getName() const { return "Derived"; }
};

int main()
{
    Derived derived {};
    Base& rBase{ derived }; //rBase is a Base reference
    std::cout << "rBase is a " << rBase.getName() << '\n';

    Base* pBase{ &derived }; ////pBase is a Base pointer
    std::cout << "pBase is a " << pBase->getName() << '\n';

    return 0;
}