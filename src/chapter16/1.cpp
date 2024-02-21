#include <iostream>
#include <vector>

int main()
{
    std::vector <int> primes { 2, 3, 5, 7, 11 }; // hold the first 5 prime numbers (as int)

    std::cout << "An int is " << sizeof(int) << " bytes\n";
    std::cout << &(primes[0]) << '\n';
    std::cout << &(primes[1]) << '\n';
    std::cout << &(primes[2]) << '\n';
    std::cout << primes[0] << '\n';   
    std::cout << primes[1] << '\n'; 

    std::vector<int> arr(3); // create a vector of length 3

	std::cout << "Enter 3 integers: ";
	std::cin >> arr[0];
    std::cin >> arr[1];
    std::cin >>  arr[2];

	std::cout << "The sum is: " << arr[0] + arr[1] + arr[2] << '\n';	

    return 0;
}