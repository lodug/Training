#include <iostream>

int getValueFromUser() // this function now returns an integer value
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value the user entered back to the caller
}

int getNumbers()
{
    return 5;
    return 7;
}

int main()
{
	int num { getValueFromUser() }; // initialize num with the return value of getValueFromUser()
	int x{ getValueFromUser() }; // first call to getValueFromUser
    int y{ getValueFromUser() }; // second call to getValueFromUser
    
	std::cout << num << " doubled is: " << num * 2 << '\n';	
	std::cout << x << " + " << y << " = " << x + y << '\n';
	// the following prints will print 5 twice (on separate lines). Both times when function getNumbers() is called, the value 5 is returned. When the return 5 statement is executed, the function is exited immediately, so the return 7 statement never executes.
	std::cout << getNumbers() << '\n'; 
    std::cout << getNumbers() << '\n';

	return 0;
}