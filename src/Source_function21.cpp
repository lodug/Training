#include <iostream>

// Definition of user-defined function doPrint()
void doPrint() // doPrint is the called function in this example
{
	std::cout << "In doPrint()\n";

}

void doB()
{
	std::cout << "In doB()\n";
}

void doA()
{
	std::cout << "Starting doA()\n";

	doB();

	std::cout << "Ending doA()\n";
}

int main() {
	std::cout <<"Starting main()\n";
	doPrint(); // Interrupt main() by making a function call to doPrint(). main() is the caller.
	doPrint(); // doPrint() called for the second time

	doA();
	
	std::cout << "Ending main()\n"; // this statement is executed after doPrint() ends

	return 0;
}