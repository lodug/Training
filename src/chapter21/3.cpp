#include <iostream>

// class Point
// {
// private:
//     double m_x{};
//     double m_y{};
//     double m_z{};

// public:
//     Point(double x=0.0, double y=0.0, double z=0.0)
//       : m_x{x}, m_y{y}, m_z{z}
//     {
//     }

//     double getX() const { return m_x; }
//     double getY() const { return m_y; }
//     double getZ() const { return m_z; }

//     void print() const
//     {
//         std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ')';
//     }
// };

// int main()
// {
//     const Point point{5.0, 6.0, 7.0};

//     std::cout << "My point is: ";
//     point.print();
//     std::cout << " in Cartesian space.\n";
// }

//it could be more easier if you type : Point point{5.0, 6.0, 7.0};
//cout << "My point is: " << point << " in Cartesian space.\n";
//like this:


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

    Point point2{2.0, 3.5, 4.0};
    Point point3{6.0, 7.5, 8.0};

    std::cout << point2 << ' ' << point3 << '\n';

    return 0;
}

//This is pretty straightforward -- note how similar our output line is to the line in the print() function we wrote previously. 
//The most notable difference is that std::cout has become parameter out (which will be a reference to std::cout when the function is called).

//This is pretty straightforward -- note how similar our output line is to the line in the print() function we wrote previously. 
//The most notable difference is that std::cout has become parameter out (which will be a reference to std::cout when the function is called).

//if you try to return std::ostream by value, you’ll get a compiler error. This happens because std::ostream specifically disallows being copied.

//In this case, we return the left hand parameter as a reference. 
//This not only prevents a copy of std::ostream from being made, it also allows us to “chain” output commands together, 
//such as std::cout << point << std::endl;