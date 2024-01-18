#include <iostream>

int foo(int n)
{
    return n + 10;
}

template <typename T>
int foo(T n)
{
    return n;
}

int main()
{
    std::cout << foo(1) << '\n'; // #1

    short s { 2 };
    std::cout << foo(s) << '\n'; // #2

    std::cout << foo<int>(4) << '\n'; // #3

    std::cout << foo<int>(s) << '\n'; // #4

    std::cout << foo<>(6) << '\n'; // #5

    return 0;
}

// In case 1, foo(1) matches foo(int) exactly, 
// so non-template function foo(int) is called.

// In case 2, foo(s) does not match non-template function foo(int)
//  exactly, 
//  but the argument s can be converted to an int so foo(int) is a candidate. 
//  However, the compiler will prefer to use function template foo<T>(T) to stencil out exact match foo<short>(short). So this calls foo<short>(short).

// In case 3, foo<int>(4) is an explicit call to foo<int>, so foo(int) isn’t considered. 
// The compiler stencils out foo<int>(int) and calls it.

// In case 4, this is also an explicit call to foo<int>. 
// The compiler promotes argument s to an int to match the parameter.

// In case 5, this syntax will only match function templates, so foo(int) is not considered. foo<int>(int) is called.