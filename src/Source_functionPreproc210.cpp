#include <iostream>

#define MY_NAME "lslslslslls"
#define PRINT_LD
#define FOO 9 // Here's a macro substitution

void foo()
{
#define NAME "L"
}

int main()
{
    std::cout << "My name is: " << MY_NAME << '\n';

    #ifdef PRINT_LD
        std::cout << "LD\n"; // will be compiled since PRINT_LD is defined
    #endif

    #ifdef PRINT_LW
        std::cout << "LW\n"; // will be excluded since PRINT_LW is not defined
    #endif

    #ifndef PRINT_LX
        std::cout << "LX\n";
    #endif

    #if 0 // Don't compile anything starting here (To temporarily re-enable code that has been wrapped in an #if 0, you can change the #if 0 to #if 1)
        std::cout << "AB\n";
        std::cout << "ZW\n";
    #endif // until this point

    #if 1// (To temporarily re-enable code that has been wrapped in an #if 0, you can change the #if 0 to #if 1)
        std::cout << "AX\n";
        std::cout << "ZX\n";
    #endif 

    #ifdef FOO // This FOO does not get replaced because it’s part of another preprocessor directive
        std::cout << FOO << '\n'; // This FOO gets replaced with 9 because it's part of the normal code
    #endif

    std::cout << "My name is: " << NAME << '\n';
    // Even though it looks like #define NAME “L” is defined inside function foo, the preprocessor won’t notice, 
    // as it doesn’t understand C++ concepts like functions. Therefore, this program behaves identically to one where #define NAME “L” was defined either before or immediately after function foo. 
    // For readability, you’ll generally want to #define identifiers outside of functions.

    return 0;
}