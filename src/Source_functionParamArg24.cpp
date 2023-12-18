#include <iostream>

// This function takes no parameters
// It does not rely on the caller for anything
void doPrint()
{
    std::cout << "In doPrint()\n";
}

// This function takes one integer parameter named x
// The caller will supply the value of x
void printValue(int x)
{
    std::cout << x  << '\n';
}

// This function has two integer parameters, one named x, and one named y
// The values of x and y are passed in by the caller
void printValues(int x, int y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

// This function has two integer parameters, one named x, and one named y
// The caller will supply the value of both x and y
int add(int x, int y)
{
    return x + y;
}

int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}

void printDouble(int value) //function with an integer parameter
{
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

// sum of ywo integers
int sum(int x,int y)
{
    return x + y;
}

int main()
{
    int num { getValueFromUser() };
    printDouble(num);
    std::cout << '\n';
    // or we can simplify the above example using the return value of function getValueFromUser directly as an argument to function printDouble!
    printDouble(getValueFromUser());
    std::cout << '\n';

    doPrint();
    printValue(2);
    add(2,3);
    printValues(4,5); // 2 arguments 4 and 5
    std::cout << sum(4, 5) << '\n'; // Arguments 4 and 5 are passed to function sum()
    
    int a{5};
    std::cout << sum(a, a) << '\n';
    std::cout << add(1, add(2, 3)) << '\n'; // evaluates 1 + (2 + 3)

    return 0;
}