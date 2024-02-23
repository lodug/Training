#include <iostream>
#include <string>

class Animal // This Animal is an abstract base class
{
protected:
    std::string m_name {};

public:
    Animal(std::string name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
    virtual std::string speak() const = 0; // note that speak is now a pure virtual function

    virtual ~Animal() = default;
};

class Cow: public Animal
{
public:
    Cow(std::string name)
        : Animal(name)
    {
    }

    std::string speak() const override { return "Moo"; }
};

int main()
{
    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    return 0;
}