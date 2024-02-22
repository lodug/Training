#include <iostream>

class Base
{
private:
	int m_value {};

public:
	Base(int value)
		: m_value { value }
	{
	}

	int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base { value }
	{
	}


	int getValue() const = delete; // mark this function as inaccessible
};

int main()
{
	Derived derived { 7 };

	// // The following won't work because getValue() has been deleted!
	// std::cout << derived.getValue();

    // We can call the Base::getValue() function directly
	std::cout << derived.Base::getValue() << '\n';

	// Or we can upcast Derived to a Base reference and getValue() will resolve to Base::getValue()
	std::cout << static_cast<Base&>(derived).getValue();

	return 0;
}

//the member functions can be marked as deleted in the derived class, which ensures they can’t be called at all through a derived object:
//the getValue() function was deleted
//This means that the compiler will complain when we try to call the derived version of the function. 
//Note that the Base version of getValue() is still accessible though. We can call Base::getValue() in one of two ways