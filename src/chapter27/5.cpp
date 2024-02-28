#include <iostream>

int main()
{
	try
	{
		throw 5; // throw an int exception
	}
	catch (double x)
	{
		std::cout << "We caught an exception of type double: " << x << '\n';
	}
	catch (...) // catch-all handler
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}
}

//Because there is no specific exception handler for type int, the catch-all handler catches this exception.
//The catch-all handler must be placed last in the catch block chain. 
//This is to ensure that exceptions can be caught by exception handlers tailored to specific data types if those handlers exist.