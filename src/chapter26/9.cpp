#include <iostream>

template <typename T, typename S>
class Pair
{
private:
	T m_x;
	S m_y;

public:
	Pair(const T& x, const S& y)
		: m_x{x}, m_y{y}
	{
	}

	T& first() { return m_x; }
	S& second() { return m_y; }
	const T& first() const { return m_x; }
	const S& second() const { return m_y; }
};

int main()
{
	Pair<int, double> p1 { 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2 { 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}

// a Pair class that allows you to specify separate types for each of the two values in the pair.