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
    //A pure virtual function makes it so the base class can not be instantiated, 
    //and the derived classes are forced to define these functions before they can be instantiated.
    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

    // pure virtual functions can be called using a reference (or pointer) to a base class:
    Animal& ra{ cow };
    std::cout << ra.speak() << '\n'; // resolves to Cow::speak(), prints "Moo"

    Animal* pa{ &cow };
    std::cout << pa->speak() << '\n'; // resolves to Cow::speak(), prints "Moo"
   
    return 0;
}