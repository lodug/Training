#include <iostream>
#include <memory> // for std::unique_ptr


class Automobil
{
private:
	int m_power{ 0 };
	
public:
	Automobil(int power = 0) :
		m_power{ power }
	{
        std::cout << "constructor m_power =" << m_power << '\n';
	}

    ~Automobil()
    {
        std::cout << "destructor m_power =" << m_power << '\n';
    }

    void print()
    {
        std::cout << "AutomobilObject m_power = " << m_power << '\n';
    }
    
};

Automobil * AutomobilMakeRawPtr(int power)
{
    return new Automobil(power);
}

std::unique_ptr<Automobil> AutomobilMakeSmartUniquePtr(int power)
{
    return std::make_unique<Automobil>(power);
}

int main()
{
    //Raw pointer
	auto RawPtr = AutomobilMakeRawPtr(50);
    RawPtr->print();

    //the destructor never gets called, so do this:
    delete(RawPtr);

    //Smart pointer: std::unique
    auto SmartPtr = AutomobilMakeSmartUniquePtr(50);
    RawPtr->print();
    //no need to delete the unique pointre, it will be delete automatically due to smart pointer std::unique

	return 0;
}