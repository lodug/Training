#include <iostream>
#include <string>

class Base
{
protected:
	int m_value{};

public:
	Base(int value)
		: m_value{value}
	{
	}

	virtual ~Base() = default;
};

class Derived : public Base
{
protected:
	std::string m_name{};

public:
	Derived(int value, std::string name)
		: Base{value}, m_name{name}
	{
	}

	const std::string& getName() const { return m_name; }
};

Base* getObject(bool returnDerived)
{
	if (returnDerived)
		return new Derived{1, "Apple"};
	else
		return new Base{2};
}

int main()
{
	Base* b{ getObject(true) };

	Derived* d{ dynamic_cast<Derived*>(b) }; // use dynamic cast to convert Base pointer into Derived pointer

	std::cout << "The name of the Derived is: " << d->getName() << '\n';

	delete b;

	return 0;
}

//The above example works because b is actually pointing to a Derived object, so converting b into a Derived pointer is successful.