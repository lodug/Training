#include <iostream>
#include <string>

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual ~Base() = default;

    virtual std::string getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

   std::string getName() const override { return "Derived"; }
};

int main()
{
    Derived derived{ 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Base& ref{ derived };
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Base* ptr{ &derived };
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';
    //ref references and ptr points to derived, which has a Base part, and a Derived part. 
    //Because ref and ptr are of type Base, ref and ptr can only see the Base part of derived -- the Derived part of derived still exists, 
    //but simply can’t be seen through ref or ptr. 
    //However, through use of virtual functions, we can access the most-derived version of a function. 
    //In the above example, ref references and ptr points to derived, which has a Base part, and a Derived part. Because ref and ptr are of type Base, 
    //ref and ptr can only see the Base part of derived -- the Derived part of derived still exists, but simply can’t be seen through ref or ptr. 
    //However, through use of virtual functions, we can access the most-derived version of a function. 
    

    Base base{ derived }; // what happens here?
    std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';
    //instead of setting a Base reference or pointer to a Derived object, we simply assign a Derived object to a Base object
    //Remember that derived has a Base part and a Derived part. When we assign a Derived object to a Base object, 
    //only the Base portion of the Derived object is copied. The Derived portion is not. 
    //In the example above, base receives a copy of the Base portion of derived, but not the Derived portion. 
    //That Derived portion has effectively been “sliced off”. 
    //Consequently, the assigning of a Derived class object to a Base class object is called object slicing (or slicing for short).

    return 0;
}