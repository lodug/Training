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

	virtual const char* getName() const { return "Base"; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base{ value }
	{
	}

	virtual const char* getName() const override { return "Derived"; }
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

// 	virtual const char* getName() { return "Base"; }
// };

// class Derived : public Base
// {
// public:
// 	Derived(int value)
// 		: Base{ value }
// 	{
// 	}

// 	virtual const char* getName() const { return "Derived"; }
// };

// int main()
// {
// 	Derived d{ 5 };
// 	Base& b{ d };
// 	std::cout << b.getName() << '\n';

// 	return 0;
// }

//the output should be Derived