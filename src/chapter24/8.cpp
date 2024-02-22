#include <iostream>
#include <string>

class Fruit
{
private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string name, std::string color)
        : m_name{ name }
        , m_color{ color }
    {

    }

    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
};

// Apple publicly inheriting Fruit
class Apple : public Fruit
{ 
private:
    double m_fiber {};

public:
    Apple(std::string name, std::string color, double fiber = 0.0)
        : Fruit{ name, color } // call Fruit(std::string, std::string) to initialize these fields
        , m_fiber{ fiber }
        {

        }

        double getFiber() const { return m_fiber; }        
};

// Banana publicly inheriting Fruit
class Banana : public Fruit
{ 
public:
    Banana(std::string name = "", std::string color = "")
        : Fruit{ name, color } // call Fruit(std::string, std::string) to initialize these fields        
        {

        }             
};

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ')' << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << "Banana(" << b.getName() << ", " << b.getColor() << ')' << '\n';

	return 0;
}