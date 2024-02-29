#include <iostream>

class A
{
private:
	int m_x;
public:
	A(int x) : m_x{x}
	{
		if (x <= 0)
			throw 1; // Exception thrown here
	}
};

class B : public A
{
public:
	B(int x) : A{x}
	{
		// What happens if creation of A fails and we want to handle it here?
	}
};

int main()
{
	try
	{
		B b{0};
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}

//derived class B calls base class constructor A, which can throw an exception. 
//Because the creation of object b has been placed inside a try block (in function main()), if A throws an exception, main’s try block will catch it. 