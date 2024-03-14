//an example of inner factory : starting from 3.cpp and added modifications

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

class Point
{  
  // use a factory method
  Point(float x, float y) : x(x), y(y) {}

//if we do this, then we can acces the private conctructor, but the question is how to expose the POintFactory
//inner factory class: it has access to the private members: can call a private constructor with any problem
  class PointFactory
  {
    PointFactory() {}
  public:
    static Point NewCartesian(float x, float y)
    {
      return { x,y };
    }
    static Point NewPolar(float r, float theta)
    {
      return{ r*cos(theta), r*sin(theta) };
    }
  };
public:
  float x, y;
  static PointFactory Factory;
};


int main()
{ 

  // if factory is public, then: not working
  //auto p = Point::PointFactory::NewCartesian(3, 4);
  
}