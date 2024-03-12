// open closed principle

// open for extension, closed for modification

#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
  string name;
  Color color;
  Size size;
};

struct ProductFilter
{
    //use a vector of pointers called by_color
    vector<Product*> by_color(vector<Product*> items, Color color)
    {
    //make the result
    vector<Product*> result;
    for (auto& i : items)
        if (i->color == color)
            //if it fits the color then add it to the result
            result.push_back(i);
    return result;
    }

    //filter by size
    vector<Product*> by_color(vector<Product*> items, Size size)
    {
    //make the result
    vector<Product*> result;
    for (auto& i : items)
        if (i->size == size)
            //if it fits the color then add it to the result
            result.push_back(i);
    return result;
    }

    //filter by color and size
    vector<Product*> by_color_and_color(vector<Product*> items, Size size, Color color)
    {
    //make the result
    vector<Product*> result;
    for (auto& i : items)
        if (i->size == size && i->color == color)
            //if it fits the color then add it to the result
            result.push_back(i);
    return result;
    }

    //it is a very problem to do this approach: if we would another criteria we'll have a lot of function, it is not optimal
    // that is why we use the open closed principle
    //open-closed principle: states that your systems should be open to extension so you should be able to extend systems by inheritance for example and whar we did above was
    //to modify existing code instead to inheriting
};

//we can build a better filter than what was written above using the specification patter, which is an enterprise patter, a pattern related to data adn working with data
// do this by defining 2 interfaces:specification and filter
template <typename T> struct Specification
{
    //add a pure virtual method which : if It's going to return a Boolean, it's going to be called is satisfied.
    //And all it tries to do is it tries to check whether some item satisfies a particular specification., 
    //And this specification is once again going to be defined through inheritance.
    // we define a virtual member, which in our case is going to return a vector of T pointers.
    //That's the result of our search and it's going to be called filter.So here we're going to take two arguments.
    //The first is a vector of T pointers specifying the items that we want to filter.And the second one is the specification that we want to filter upon.
    virtual bool is_satisfied(T* item) = 0;
};

// filter is going to define the interface that needs to be implemented by any kind of filter, like a filter of items.
template <typename T> struct Filter
{
    // add a pure virtual method which : if it return a boolean 
    virtual vector<T*> filter(vetcor<T*> items, Specification<T)
};



int main()
{
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  //make a vector of pointers
  const vector<Product*> items { &apple, &tree, &house };

  ProductFilter pf;
  auto green_things = pf.by_color(items, Color::green);
  for (auto& item : green_things)
  cout << item->name << "is green\n ";

  return 0;
}
