//an example of factory : starting from 2.cpp and added modifications

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

class Point
{ 
public:   
  Point(const float x, const float y)
    : x{x},
      y{y}
  {
  }

  float x, y; 
  
  friend std::ostream& operator<<(std::ostream& os, const Point& obj)
  {
    return os
      << "x: " << obj.x
      << " y: " << obj.y;
  }
};

//factory:
struct POIntFactory
{
    //how to construct a new cartesian point: using a factory method
  static Point NewCartesian(float x, float y)
  {
    return{ x,y };
  }
  static Point NewPolar(float r, float theta)
  {
    return{ r*cos(theta), r*sin(theta) };
  }
};

int main()
{ 
  auto p = POIntFactory::NewPolar(5, M_PI_4);
  std::cout << p << std::endl;
 
}