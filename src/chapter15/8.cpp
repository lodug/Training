#include <iostream>
#include <string>

template <typename T1, typename T2, typename T3>
class Triad
{
private:
    T1 m_first{};
    T2 m_second{};
    T3 m_third{};

public:
    //Since our class data members are of type T1, T2, T3, we make the parameters of our constructor type const T1&, T2&, T3&,
    //so the user can supply initialization values of the same type. Because T might be expensive to copy, it’s safer to pass by const reference than by value.
    //constructor
    Triad(const T1& first, const T2& second, const T3& third)
        : m_first{ first}
        , m_second{ second }
        , m_third{ third }
    {

    }

    //access functions
    const T1& first() const { return m_first; }
	const T2& second() const { return m_second; }
	const T3& third() const { return m_third; }

	void print() const;

};

template <typename T1, typename T2, typename T3>
void Triad<T1, T2, T3>::print() const
{
	std::cout << '[' << m_first << ", " << m_second << ", " << m_third << ']' ;
}

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';

	std::cout << t1.first() << '\n';

    Triad<int, double, std::string> t2{ 1, 2.3, "Hello" };
	t2.print();
	std::cout << '\n';

	return 0;
}