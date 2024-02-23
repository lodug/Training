#include <iostream>
#include <string>

class A
{
public:
	virtual std::string getName1(int x) { return "A"; }
	virtual std::string getName2(int x) { return "A"; }
};

class B : public A
{
public:
	virtual std::string getName1(short x) { return "B"; } // note: parameter is a short
	virtual std::string getName2(int x) const { return "B"; } // note: function is const
};

int main()
{
	B b{};
	A& rBase{ b };
	std::cout << rBase.getName1(1) << '\n';
	std::cout << rBase.getName2(2) << '\n';

	return 0;
}

//Because rBase is an A reference to a B object, the intention here is to use virtual functions to access B::getName1() and B::getName2(). 
//However, because B::getName1() takes a different parameter (a short instead of an int), it’s not considered an override of A::getName1(). 
//More insidiously, because B::getName2() is const and A::getName2() isn’t, B::getName2() isn’t considered an override of A::getName2().