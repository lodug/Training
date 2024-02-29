#include <iostream>
#include <stdexcept> // for std::runtime_error
#include <exception> // for std::exception

class Fraction
{
private:
	int m_numerator = 0;
	int m_denominator = 1;

public:
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }
		, m_denominator{ denominator }
	{
		if (m_denominator == 0)
			throw std::runtime_error("Invalid denominator");
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

int main()
{
	std::cout << "Enter the numerator: ";
	int numerator{};
	std::cin >> numerator;

	std::cout << "Enter the denominator: ";
	int denominator{};
	std::cin >> denominator;

	try
	{
		Fraction f{ numerator, denominator };
		std::cout << "Your fraction is: " << f << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}

//Write a Fraction class that has a constructor that takes a numerator and a denominator. I
// If the user passes in a denominator of 0, throw an exception of type std::runtime_error (included in the stdexcept header). 
//In your main program, ask the user to enter two integers. 
//If the Fraction is valid, print the fraction. If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.