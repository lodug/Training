#include <iostream>

int main()
{
    int count{ 1 };
    while (count <=10)
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "done\n";
     
    int count1{ 15 };
    while (count1 <= 10)
    {
        std::cout << count1 << ' ';
        ++count1;
    }

    std::cout << "only this line!\n";

    // int count2{ 1 };
    // while (count2 <= 10) // this condition will never be false
    // {
    //     std::cout << count2 << ' '; // so this line will repeatedly execute
    // }

    // std::cout << '\n'; // this line will never execute


    return 0;
;}