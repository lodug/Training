#include <iostream>

int main()
{
    for (int i{1}; i<=10; ++i)
        std::cout << i << ' ';

    std::cout <<'\n';

    for (int i{ 9 }; i >= 0; --i)
        std::cout << i << ' ';

    std::cout << '\n';

    for (int i { 0 }; i != 10; ++i) // uses !=        
        std::cout << i << ' ';

    std::cout << '\n';

    return 0;
}