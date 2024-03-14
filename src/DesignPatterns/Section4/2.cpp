//an example of factory method : an improvment of 1.cpp
//this implementation factory method: uses static methods which allow us to construct particular object: in this case we have 2 factory methods: the static ones

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

//in order to represent in polar coordinate we do it:
enum class PointType
{
    cartesian,
    polar
};

//encapsulation
class Point
{ 
    //a private constructor
  Point(const float x, const float y)
    : x{x},
      y{y}
  {
  }

public:
  float x, y;
  
  //how to construct a new cartesian point: using a factory method
  static Point NewCartesian(float x, float y)
  {
    return{ x,y };
  }
  static Point NewPolar(float r, float theta)
  {
    return{ r*cos(theta), r*sin(theta) };
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& obj)
  {
    return os
      << "x: " << obj.x
      << " y: " << obj.y;
  }
};

int main()
{
  // will not work because the constructor is private
  //Point p{ 1,2 };

  //you can do this: for this #define _USE_MATH_DEFINES
  auto p = Point::NewPolar(5, M_PI_4);
  //for this to work generate the ostream operator above: we can construct the point from the polar coordinates
  std::cout << p << std::endl;



}