#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> prime{ 2, 3, 5, 7, 11 };

    std::cout << prime.at(3) << '\n'; // print the value of element with index 3
    //std::cout << prime.at(9); // invalid index (throws exception)
 
    std::vector<char> arr { 'h', 'e', 'l', 'l', 'o' };    
    std::cout << arr[1] << arr.at(1) << '\n';

    return 0;
}