#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    void print()
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction fCopy { f }; // What constructor is used here? A copy constructor is a constructor that is used to initialize an object with an existing object of the same type. After the copy constructor executes, the newly created object should be a copy of the object passed in as the initializer.

    f.print();
    fCopy.print();
    //By default, the implicit copy constructor will do memberwise initialization. 
    //This means each member will be initialized using the corresponding member of the class passed in as the initializer. 
    //In the example above, fCopy.m_numerator is initialized using f.m_numerator (which has value 5), 
    //and fCopy.m_denominator is initialized using f.m_denominator (which has value 3).
    //After the copy constructor has executed, the members of f and fCopy have the same values, so fCopy is a copy of f. 
    //Thus calling print() on either has the same result.

    return 0;
}