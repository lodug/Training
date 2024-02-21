#include <iostream>
#include <vector>

int main()
{
    std::vector<int> fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    std::size_t length { fibonacci.size() };
    for (std::size_t index { 0 }; index < length; ++index)
       std::cout << fibonacci[index] << ' ';

    std::cout << '\n';

    //this example does not require us to use the array’s length, nor does it require us to index the array!: The range-based loop
    for (int num : fibonacci) // iterate over array fibonacci and copy each value into `num`
       std::cout << num << ' '; // print the current value of `num`

    std::cout << '\n';

    //Use type deduction (auto) with range-based for loops to have the compiler deduce the type of the array element.
    for (auto num : fibonacci) // compiler will deduce type of num to be `int`
       std::cout << num << ' ';


    return 0;
}