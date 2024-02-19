#include <iostream>

class IntPair
{
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}

    int x() const { return m_x; }
    int y() const{ return m_y; }
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

int main()
{
    // Case 1: Pass variable : create named object p initialized with value { 1, 2 }
    IntPair p { 3, 4 };
    print(p);

    // Case 2: Construct temporary IntPair object and pass to function: create temporary object initialized with value { 1, 2 }
    print(IntPair { 5, 6 } );

    // Case 3: Implicitly convert { 7, 8 } to a temporary Intpair object and pass to function: compiler will try to convert value { 1, 2 } to temporary object
    print( { 7, 8 } );

    return 0;
}