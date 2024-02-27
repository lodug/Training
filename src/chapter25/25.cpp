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

	virtual const char* getName() const { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	const char* getName() const { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

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

// 	const char* getName() const { return "Base"; }
// };

// class Derived : public Base
// {
// public:
// 	Derived(int value)
// 		: Base{ value }
// 	{
// 	}

// 	const char* getName() const { return "Derived"; }
// };

// int main()
// {
// 	Derived d{ 5 };
// 	Base& b{ d };
// 	std::cout << b.getName() << '\n';

// 	return 0;
// }

//The output of the program is supposed to be “Derived”.