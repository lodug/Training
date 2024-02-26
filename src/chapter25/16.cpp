#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
		std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power }
    {
		std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power }
    {
		std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

int main()
{
    Copier copier{ 1, 2, 3 };

    return 0;
}

//PoweredDevice got constructed twice.
//While this is often desired, other times you may want only one copy of PoweredDevice to be shared by both Scanner and Printer.
//To share a base class, simply insert the “virtual” keyword in the inheritance list of the derived class. This creates what is called a virtual base class, which means there is only one base object. 
//The base object is shared between all objects in the inheritance tree and it is only constructed once
