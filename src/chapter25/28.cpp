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

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	const char* getName() override { return "Derived"; }
};

int main()
{
	Derived d{ 5 };
	Base& b{ d };
	std::cout << b.getName() << '\n';

	return 0;
}

// #include <iostream>

// class Base final
// {
// protected:
// 	int m_value;

// public:
// 	Base(int value)
// 		: m_value{ value }
// 	{
// 	}

// 	virtual const char* getName() { return "Base"; }
// };

// class Derived : public Base
// {
// public:
// 	Derived(int value)
// 		: Base{ value }
// 	{
// 	}

// 	const char* getName() override { return "Derived"; }
// };

// int main()
// {
// 	Derived d{ 5 };
// 	Base& b{ d };
// 	std::cout << b.getName() << '\n';

// 	return 0;
// }

//compile error because Base was declared as final, and can't deruve Derived from it