#include <iostream>
#include <string>

template <typename T, typename S>
class Pair
{
private:
	T m_x{};
	S m_y{};

public:
	Pair(const T& x, const S& y)
		: m_x{ x }, m_y{ y }
	{
	}

	T& first() { return m_x; }
	S& second() { return m_y; }
	const T& first() const { return m_x; }
	const S& second() const { return m_y; }
};

template <typename S>
class StringValuePair : public Pair<std::string, S>
{
public:
	StringValuePair(std::string key, const S& value)               
		: Pair<std::string, S>{ static_cast<std::string>(key), value }
	{
	}
};

int main()
{
	// StringValuePair<int> svp{ "Hello", 5 };
	// std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    StringValuePair<std::string> svp{ "Hello", "world" };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';


	return 0;
}

//Write a template class named StringValuePair that inherits from a partially specialized Pair class (using std::string as the first type, 
//and allowing the user to specify the second type).