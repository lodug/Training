//overload the subscript operator ([]) to allow access to the elements of m_list. 
//The subscript operator is one of the operators that must be overloaded as a member function. 
//An overloaded operator[] function will always take one parameter: the subscript that the user places between the hard braces. 
//In our IntList case, we expect the user to pass in an integer index, and we’ll return an integer value back as a result.

#include <iostream>

class IntList
{
private:
    int m_list[10]{};

public:
    int& operator[] (int index)
    {
        return m_list[index];
    }
};

/*
// Can also be implemented outside the class definition
int& IntList::operator[] (int index)
{
    return m_list[index];
}
*/

int main()
{
    IntList list{};
    list[2] = 3; // set a value
    std::cout << list[2] << '\n'; // get a value

    return 0;
}

//whenever we use the subscript operator ([]) on an object of our class, the compiler will return the corresponding element from the m_list member variable! 
//This allows us to both get and set values of m_list directly.