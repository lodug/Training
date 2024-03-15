//Liskov Substitution Principle

// Objects in a program should be replaceable with instances of their subtypes
// w/o altering the correctness of the program

#include <iostream>

class Rectangle
{
protected:
  int width, height;

public:
  Rectangle(const int width, const int height)
    : width{width}
    , height{height} { }

  int get_width() const { return width; }
  virtual void set_width(const int width) { this->width = width; }
  int get_height() const { return height; }
  virtual void set_height(const int height) { this->height = height; }

  int area() const { return width * height; }
};

//make a square class which inherits from rectangle class to customize the code a little bit
class Square : public Rectangle
{
public:
   //constructor
  Square(int size): Rectangle(size,size) {}
  void set_width(const int width) override {
    //tryng to set both dimensions at the same time
    this->width = height = width;
  }
  void set_height(const int height) override {
    this->height = width = height;
  }
};

// a function that takes Rectangle reference called r
void process(Rectangle& r)
{
  int w = r.get_width();
  r.set_height(10);

  std::cout << "expected area = " << (w * 10) 
    << ", got " << r.area() << std::endl;
};
//what we have done was to violate the Liskov Substitution principle
//a function that takes a base class: any derived class should be able to be substituted into this function without any rpoblems

//in order to not violate this principle, do it:
struct RectangleFactory
{
  static Rectangle create_rectangle(int w, int h);
  static Rectangle create_square(int size);
};

int main()
{
  Rectangle r{ 3,4 };
  process(r);

  //related to the comment where the Liskov principle was violated, if we make a square with the size of 5 and call the process
  //something unpleasant will happen: it will result an unexpected area: expected area = 50, got 100 (bevause width was set to 10)
  Square s{ 5 };  
  process(s);

  return 0;
}
