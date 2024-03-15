#include <iostream>
#include <memory> // for std::unique_ptr


class Automobil
{
private:
	int m_power{ 0 };
	
public:

    //constructor
	Automobil(int power = 0) :
		m_power{ power }
	{
        std::cout << "constructor m_power =" << m_power << '\n';
	}
    //destructor
    ~Automobil()
    {
        std::cout << "destructor m_power =" << m_power << '\n';
    }

    void print()
    {
        std::cout << "AutomobilObject m_power = " << m_power << '\n';
    }
    
};

//function that creates the Automobil objects and will return an object pointer
Automobil * AutomobilMakeRawPtr(int power)
{
    //return a new raw pointer
    return new Automobil(power);
}

//this function will return an unique pointer
std::unique_ptr<Automobil> AutomobilMakeSmartUniquePtr(int power)
{
    //this will make Automobil object and will return an unique pointer through that class, initalize that with "power"
    return std::make_unique<Automobil>(power);
}

int main()
{
    //creates two pointers RawPtr and SmartPtr using auto so that to no worry what about type it is
    //Raw pointer
	auto RawPtr = AutomobilMakeRawPtr(50);
    RawPtr->print();
    
    //the destructor never gets called, so do this in order to be called:
    delete(RawPtr);
    
    //Smart pointer: std::unique
    auto SmartPtr = AutomobilMakeSmartUniquePtr(40);
    RawPtr->print();
    //no need to delete the unique pointer, it will call the destructor automatically due to smart pointer std::unique 

	return 0;
}

// when using a smart pointer the destructor is called when the pointer goes out of scope, unlike raw pointer
// using unique pointers is more easier than using raw pointers due to memory management in order to avoid memory errors