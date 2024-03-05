#include <iostream>

void fun(const int& lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const: " << lref << '\n';
}

void fun(int&& rref) // r-value arguments will select this function
{
	std::cout << "r-value reference: " << rref << '\n';
}

int main()
{
	int x{ 5 };
	fun(x); // l-value argument calls l-value version of function
	fun(5); // r-value argument calls r-value version of function

	return 0;
}

//As you can see, when passed an l-value, the overloaded function resolved to the version with the l-value reference. When passed an r-value, 
//the overloaded function resolved to the version with the r-value reference (this is considered a better match than an l-value reference to const).