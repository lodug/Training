#include <iostream>

template <typename T>
void print(const T& t)
{
    std::cout << t << '\n';
}

// A specialized function template
template<> // template parameter declaration containing no template parameters
void print<double>(const double& d)
{
    std::cout << std::scientific << d << '\n';
}

int main()
{
    print(5);
    print(6.7);

    return 0;
}

//First, we need a template parameter declaration to tell the compiler that we’re defining a function template. However, in this case, we don’t actually need any template parameters, so we don’t put anything between the angled brackets. On the next line, print<double> tells the compiler that we’re specializing the print template function for type double. 
//The rest of the function is the same as the non-template version.