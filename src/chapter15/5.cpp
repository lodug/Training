#include <iostream>

class Fruit
{
public:
	// FruitType has been moved inside the class, under the public access specifier
        // We've also renamed it Type and made it an enum rather than an enum class
	enum Type
	{
		apple,
		banana,
		cherry
	};

private:
	Type m_type {};
	int m_percentageEaten { 0 };

public:
	Fruit(Type type) :
		m_type { type }
	{
	}

	Type getType() { return m_type;  }
	int getPercentageEaten() { return m_percentageEaten;  }

	bool isApple() { return m_type == apple; } // Inside members of Fruit, we no longer need to prefix enumerators with FruitType::
};

int main()
{
	// Note: Outside the class, we access the enumerators via the Fruit:: prefix now
	Fruit apple { Fruit::apple };

	if (apple.getType() == Fruit::apple)
		std::cout << "I am an apple" << '\n';
	else
		std::cout << "I am not an apple" << '\n';   

    if  (apple.getType() == Fruit::cherry)  
        std::cout << "I am an cherry" << '\n';
    else
		std::cout << "I am not an cherry" << '\n';

    std::cout << apple.isApple() << '\n';    

	return 0;
}