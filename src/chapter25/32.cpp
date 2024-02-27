#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
      : m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')'; // actual output done here

    return out; // return std::ostream so we can chain calls to operator<<
}

int main()
{
    const Point point1{2.0, 3.0, 4.0};

    std::cout << point1 << '\n';

    return 0;
}

//Overloading operator<< is similar to overloading operator+ (they are both binary operators), except that the parameter types are different.
//Consider the expression std::cout << point. If the operator is <<, what are the operands? 
//The left operand is the std::cout object, and the right operand is your Point class object. std::cout is actually an object of type std::ostream
//// std::ostream is the type for object std::cout
//friend std::ostream& operator<< (std::ostream& out, const Point& point);
//Implementation of operator<< for our Point class is fairly straightforward -- because C++ already knows how to output doubles using operator<<, 
//and our members are all doubles, we can simply use operator<< to output the member variables of our Point.