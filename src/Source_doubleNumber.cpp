#include <iostream>

int main() {
	
	std::cout << "enter an integer: ";
	int x{}; 
    std::cin >> x;

	std::cout << "enter another integer: ";
	int y{};
	std::cin >> y;	
		
	std::cout << "Double that number is: " << x * 2 << '\n'; // prints the double of x
	std::cout << "Triple that number is: " << x * 3<< '\n'; // prints the triple of x
	std::cout << x << " + " << y << " is "<< x+y << '\n'; 
	std::cout << x << " - " << y << " is "<< x-y << '\n'; 
	
	return 0;
}