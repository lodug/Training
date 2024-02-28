#include <iostream>

template <typename T>
class Pair1
{
private:
	T m_x {};
	T m_y {};

public:
	Pair1(const T& x, const T& y)
		: m_x{ x }, m_y{ y }
	{
	}

	T& first() { return m_x; }
	T& second() { return m_y; }
	const T& first() const { return m_x; }
	const T& second() const { return m_y; }
};

int main()
{
	Pair1<int> p1 { 5, 8 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2 { 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}

//a templated class named Pair1 that allows the user to define one template type that is used for both values in the pair.