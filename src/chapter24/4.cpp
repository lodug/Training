#include <iostream>

class Base
{
public:
    int m_id {};

    Base(int id=0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
};

class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0, int id=0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};

int main()
{
    Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    return 0;
}

// All that’s happening is that the Derived constructor is calling a specific Base constructor to initialize the Base portion of the object. 
// Because m_id lives in the Base portion of the object, the Base constructor is the only constructor that can initialize that value.
// Note that it doesn’t matter where in the Derived constructor member initializer list the Base constructor is called -- it will always execute first.