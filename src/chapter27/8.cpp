#include <iostream>

class Base
{
public:
    Base() {}
};

class Derived: public Base
{
public:
    Derived() {}
};

int main()
{

    // try
    // {
    //     throw Derived();
    // }
    // catch (const Base& base)
    // {
    //     std::cerr << "caught Base";
    // }
    // catch (const Derived& derived)
    // {
    //     std::cerr << "caught Derived";
    // }

    //output: caught Base

    try
    {
        throw Derived();
    }
    catch (const Derived& derived)
    {
        std::cerr << "caught Derived";
    }
    catch (const Base& base)
    {
        std::cerr << "caught Base";
    }

    return 0;
}

//This way, the Derived handler will get first shot at catching objects of type Derived (before the handler for Base can). 
//Objects of type Base will not match the Derived handler (Derived is-a Base, but Base is not a Derived), and thus will “fall through” to the Base handler.

//Handlers for derived exception classes should be listed before those for base classes.