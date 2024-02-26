#include <iostream>

class Base
{
public:
	virtual void print() const { std::cout << "Base";  }
};

class Derived : public Base
{
public:
	void print() const override { std::cout << "Derived"; }
};

int main()
{
	Derived d{};
	Base& b{ d };
	b.print(); // will call Derived::print()

	return 0;
}

//b.print() will call Derived::print() (because b is referencing a Derived class object, 
//Base::print() is a virtual function, and Derived::print() is an override).