#include <iostream>
#include <string>

class A
{
public:
	A() { std::cout << getName(); } // note addition of constructor (getName() now called from here)

	virtual std::string getName() const { return "A"; }
};

class B : public A
{
public:
	virtual std::string getName() const { return "B"; }
};

class C : public B
{
public:
	virtual std::string getName() const { return "C"; }
};

class D : public C
{
public:
	virtual std::string getName() const { return "D"; }
};

int main()
{
	C c {};

	return 0;
}

//When we create a C object, the A part is constructed first. When the A constructor is called to do this, it calls virtual function getName(). 
//Because the B and C parts of the class aren’t set up yet, this resolves to A::getName()