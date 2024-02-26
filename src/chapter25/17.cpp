#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
		std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power } // this line is required to create Scanner objects, but ignored in this case
    {
		std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power } // this line is required to create Printer objects, but ignored in this case
    {
		std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : PoweredDevice{ power }, // PoweredDevice is constructed here
        Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

int main()
{
    Copier copier{ 1, 2, 3 };

    return 0;
}

//created a Copier class object: get only one copy of PoweredDevice per Copier that will be shared by both Scanner and Printer.
//However, this leads to one more problem: if Scanner and Printer share a PoweredDevice base class, who is responsible for creating it? 
//The answer, as it turns out, is Copier. The Copier constructor is responsible for creating PoweredDevice. 
//Consequently, this is one time when Copier is allowed to call a non-immediate-parent constructor directly

//First, for the constructor of the most derived class, 
//virtual base classes are always created before non-virtual base classes, which ensures all bases get created before their derived classes.
