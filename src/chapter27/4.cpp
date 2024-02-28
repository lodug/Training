#include <iostream>
#include <cmath> // for sqrt() function

// A modular square root function
double mySqrt(double x)
{
    // If the user entered a negative number, this is an error condition
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char*

    return std::sqrt(x);
}

int main()
{
    std::cout << "Enter a number: ";
    double x;
    std::cin >> x;

    // Look ma, no exception handler!
    std::cout << "The sqrt of " << x << " is " << mySqrt(x) << '\n';

    return 0;
}

//let’s say the user enters -4, and mySqrt(-4) raises an exception. Function mySqrt() doesn’t handle the exception, so the program looks to see if some function down the call stack will handle the exception. 
//main() does not have a handler for this exception either, so no handler can be found.

//When no exception handler for a function can be found, std::terminate() is called, and the application is terminated. In suc
//h cases, the call stack may or may not be unwound! If the stack is not unwound, local variables will not be destroyed,
// and any cleanup expected upon destruction of said variables will not happen!