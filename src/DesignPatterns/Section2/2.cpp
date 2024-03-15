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
    typedef vector<Product*> Items;
    Items by_color(Items items, const Color color)
    {
    //make the result    
    Items result;
    for (auto& i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
    }

    //filter by size
    Items by_size(Items items, const Size size)
    {
    //make the result    
    Items result;
    for (auto& i : items)
    ////if it fits the color then add it to the result
      if (i->size == size)
        result.push_back(i);
    return result;
    }

    //filter by color and size
    Items by_size_and_color(Items items, const Size size, const Color color)  
    {
    Items result;
    for (auto& i : items)
      if (i->size == size && i->color == color)
        result.push_back(i);
    return result;
  }
};

    //it is a very problem to do this approach: if we would another criteria we'll have a lot of function, it is not optimal

    //keep these for the explanations
//     // that is why we use the open closed principle
//     //open-closed principle: states that your systems should be open to extension so you should be able to extend systems by inheritance for example and whar we did above was
//     //to modify existing code instead to inheriting
// };

// //we can build a better filter than what was written above using the specification patter, which is an enterprise patter, a pattern related to data adn working with data
// // do this by defining 2 interfaces:specification and filter
// template <typename T> struct Specification
// {
//     //add a pure virtual method which : if It's going to return a Boolean, it's going to be called is satisfied.
//     //And all it tries to do is it tries to check whether some item satisfies a particular specification., 
//     //And this specification is once again going to be defined through inheritance.    
//     virtual bool is_satisfied(T* item) = 0;
// };

// // filter is going to define the interface that needs to be implemented by any kind of filter, like a filter of items.
// template <typename T> struct Filter
// {
//     // add a pure virtual method which : if it return a boolean 
//     // we define a virtual member, which in our case is going to return a vector of T pointers.
//     //That's the result of our search and it's going to be called filter.So here we're going to take two arguments.
//     //The first is a vector of T pointers specifying the items that we want to filter.And the second one is the specification that we want to filter upon: spec taken by reference
//     virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
// };

// //make a better filter of the product:
// struct BetterFilter : Filter<Product>
// {
//    vector<Product*> filter(vector<Product*> items, Specification<Product> &spec) override
//   {
//     vector<Product*> result;
//     for (auto& p : items)
//       if (spec.is_satisfied(p))
//         result.push_back(p);
//     return result;
//   }
// };

// struct ColorSpecification : Specification<Product>
// {
//   Color color;

//   ColorSpecification(Color color) : color(color) {}

//   bool is_satisfied(Product *item) const override {
//     return item->color == color;
//   }
// };

// struct SizeSpecification : Specification<Product>
// {
//   Size size;

//   explicit SizeSpecification(const Size size)
//     : size{ size }
//   {
//   }

//   bool is_satisfied(Product* item) const override 
//   {
//     return item->size == size;
//   }
// };

// template <typename T> struct AndSpecification : Specification<T>
// {
//   const Specification<T>& first;
//   const Specification<T>& second;

//   AndSpecification(const Specification<T>& first, const Specification<T>& second) 
//     : first(first), second(second) {}

//   bool is_satisfied(T *item) const override {
//     return first.is_satisfied(item) && second.is_satisfied(item);
//   }
// };

template <typename T> struct AndSpecification;

template <typename T> struct Specification
{
  virtual ~Specification() = default;
  virtual bool is_satisfied(T* item) const = 0;

  // new: breaks OCP if you add it post-hoc:it let us filtering green and large in a more compact way
  /*AndSpecification<T> operator&&(Specification<T>&& other)
  {
    return AndSpecification<T>(*this, other);
  }*/
};

// new: 
template <typename T> AndSpecification<T> operator&&
  (const Specification<T>& first, const Specification<T>& second)
{
  return { first, second };
}

template <typename T> struct Filter
{
  virtual vector<T*> filter(vector<T*> items,
                            Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>
{
  vector<Product*> filter(vector<Product*> items,
                           Specification<Product> &spec) override
  {
    vector<Product*> result;
    for (auto& p : items)
      if (spec.is_satisfied(p))
        result.push_back(p);
    return result;
  }
};

struct ColorSpecification : Specification<Product>
{
  Color color;

  ColorSpecification(Color color) : color(color) {}

  bool is_satisfied(Product *item) const override {
    return item->color == color;
  }
};

struct SizeSpecification : Specification<Product>
{
  Size size;

  explicit SizeSpecification(const Size size)
    : size{ size }
  {
  }


  bool is_satisfied(Product* item) const override {
    return item->size == size;
  }
};

//AndSpecification will inherit from Specification
template <typename T> struct AndSpecification : Specification<T>
{
  //I will have a specification of T, reference called first
  const Specification<T>& first;
  const Specification<T>& second;

   //constructor
  AndSpecification(const Specification<T>& first, const Specification<T>& second) 
    : first(first), second(second) {}

  bool is_satisfied(T *item) const override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

int main()
{
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  //make a vector of pointers
  const vector<Product*> items { &apple, &tree, &house };

//   ProductFilter pf;
//   auto green_things = pf.by_color(items, Color::green);
//   for (auto& item : green_things)
//   cout << item->name << "is green\n ";

   const vector<Product*> all { &apple, &tree, &house };

  //instead of writing as above 4 line, we can write like this:
   BetterFilter bf;
  ColorSpecification green(Color::green);
  auto green_things = bf.filter(all, green);
  for (auto& x : green_things)
    cout << x->name << " is green\n";


  SizeSpecification large(Size::large);
  //need the Product name here because it is a template class
  AndSpecification<Product> green_and_large(green, large);

  //auto big_green_things = bf.filter(all, green_and_large);

  // use the operator instead (same for || etc.)
  auto spec = green && large;
  for (auto& x : bf.filter(all, spec))
    cout << x->name << " is green and large\n";

  // warning: the following will compile but will NOT work
  // auto spec2 = SizeSpecification{Size::large} &&
  //              ColorSpecification{Color::blue};

  getchar();

  return 0;
}
