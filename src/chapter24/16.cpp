#include <iostream>

class Base
{
protected:
	int m_x {};
public:
	Base(int x): m_x{ x }
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}

	void print() const { std::cout << "Base: " << m_x << '\n';  }
};

class Derived: public Base
{
public:
	Derived(int y):  Base{ y }
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}

	void print() const { std::cout << "Derived: " << m_x << '\n'; }
};

int main()
{
    
	Derived d{ 5 };
	d.print();
    Base b{3};

	return 0;
}