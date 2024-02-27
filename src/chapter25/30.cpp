#include <iostream>

class Base
{
protected:
	int m_value;

public:
	Base(int value)
		: m_value{ value }
	{
	}

    virtual ~Base() = default;

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() { return "Derived"; }
};

int main()
{
	auto* d{ new Derived(5) };
	Base* b{ d };
	std::cout << b->getName() << '\n';
	delete b;

	return 0;
}

// #include <iostream>

// class Base
// {
// protected:
// 	int m_value;

// public:
// 	Base(int value)
// 		: m_value{ value }
// 	{
// 	}

//     virtual ~Base() = default;

// 	virtual const char* getName() { return "Base"; }
// };

// class Derived : public Base
// {
// public:
// 	Derived(int value)
// 		: Base{ value }
// 	{
// 	}

// 	virtual const char* getName() { return "Derived"; }
// };

// int main()
// {
// 	auto* d{ new Derived(5) };
// 	Base* b{ d };
// 	std::cout << b->getName() << '\n';
// 	delete b;

// 	return 0;
// }

//This program actually produces the right output, but has a different issue. 
//We’re deleting b, which is a Base pointer, but we never added a virtual destructor to the Base class. 
//Consequently, the program only deletes the Base portion of the Derived object, and the Derived portion is left as leaked memory.