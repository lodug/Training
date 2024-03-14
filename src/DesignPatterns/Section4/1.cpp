//an example of factory design pattern

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cmath>
using namespace std;

//in order to represent in polar coordinate we do it:
enum class PointType
{
    cartesian,
    polar
};

//build a structure that represents a 2 dimensional point
struct POint
{
    // //constructor that initializes x and y (cartesian coordinates)
    // POint(float x, float y): x(x), y(y)
    // {
    // }

    // //what if I want the coordinates in polar? but we can't have the same constructor with the same type of arguments
    // POint(float rho, float theta): x(x), y(y)
    // {
    // }

    //now that we have the enum class, we do it instead of what it was above
    //there is a problem with this constructor because a and b are a bit silly, they are not very useful and what they are use for: a for x and rho..
    //see in the next example a better way
    POint(float a, float b, PointType type = PointType::cartesian)
    {
        if (type == PointType::cartesian)
        {
            x = a;
            y = b;
        }
        else
        {
            x = a * cos(b);
            y = a * sin(b);
        }
    }


    float x, y;
};

int main()
{

}