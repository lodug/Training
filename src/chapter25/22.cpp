#include <iostream>

class Base
{
public:
	virtual void print() const { std::cout << "Base"; }

	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	void print() const override { std::cout << "Derived"; }

	friend std::ostream& operator<<(std::ostream& out, const Derived& d)
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b{};
	std::cout << b << '\n';

	Derived d{};
	std::cout << d << '\n';

    Base& bref{ d };
    std::cout << bref << '\n';
    //our version of operator<< that handles Base objects isn’t virtual, 
    //so std::cout << bref calls the version of operator<< that handles Base objects rather than Derived objects.


	return 0;
}

//we set up operator<< as a friend in our base class as usual. But rather than have operator<< determine what to print, 
//we will instead have it call a normal member function that can be virtualized! 
//This virtual function will do the work of determining what to print for each class.
