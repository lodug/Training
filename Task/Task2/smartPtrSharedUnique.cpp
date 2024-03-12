#include <iostream>
#include <memory> 
#include <string>

//std::shared_ptr vs std::unique_ptr

//print pointers
void print(std:: shared_ptr<std::string> &color1, std::shared_ptr<std::string> &color2, std:: unique_ptr<std::string> &color3, std::unique_ptr<std::string> &color4)
{
    std::cout << "Shared pointer 1: " << *color1 << " count " << color1.use_count() << '\n';
    std::cout << "Shared pointer 2: " << *color2 << " count " << color2.use_count() << '\n';
    std::cout << "UNique pointer 1: " << *color3 << '\n';
    std::cout << "Unique pointer 2: " << *color4 << '\n';
    std::cout << '\n';
}

int main()
{
    //define a shared smart pointer object:
	std::shared_ptr<std::string> sharedPtr1(new std::string("red"));
    //declare a shared pointer using std::make_shared function
    auto sharedPtr2 = std::make_shared<std::string>("blue");
   
    //define a unique smart pointer object:
	std::unique_ptr<std::string> uniquePtr1(new std::string("pink"));
    //declare a unique pointer using std::make_unique function (using auto - no need to think about what the type of this variable is)
    auto uniquePtr2 = std::make_unique<std::string>("white");
 
    //call print
    print(sharedPtr1, sharedPtr2, uniquePtr1, uniquePtr2);

    //change the value of shared pointer 1
    *sharedPtr1 = "green";
    std::cout << "sharedPtr1 changed: " << '\n';
    print(sharedPtr1, sharedPtr2, uniquePtr1, uniquePtr2);

    //change the value of unique pointer 1
    *uniquePtr1 = "brown";
    std::cout << "uniquePtr1 changed: " << '\n';
    print(sharedPtr1, sharedPtr2, uniquePtr1, uniquePtr2);

    // sharedPtr2  will point to what sharedPtr1 is pointing to:create anither shared pointer pointing to the same object
    sharedPtr2 = sharedPtr1;
    std::cout << "sharedPtr2 = sharedPtr1: " << '\n';
    print(sharedPtr1, sharedPtr2, uniquePtr1, uniquePtr2);

    //sharedPtr2 = new std::string("violet"); //this does not work: we can't assign a general pointer to a shared pointer 
    //we call the reset member function of shared pointer and we passs to that a new std::string
    sharedPtr2.reset(new std::string("violet"));
    std::cout << "sharedPtr2 changed " << '\n';
    print(sharedPtr1, sharedPtr2, uniquePtr1, uniquePtr2); 

    //for unique: because it is a unique pointer it means we can't copy that like this
    //uniquePtr1 = uniquePtr2;
    //we need to do it:
    uniquePtr1 = std::move(uniquePtr2); 
    std::cout << "uniquePtr1 = std::move(uniquePtr2)  " << '\n';
    //print(sharedPtr1, sharedPtr2, uniquePtr1, uniquePtr2); //an error: fault segmentation because we transfered the responsabilities 
    //of uniquePtr2 to uniquePtr1 (we free ptr2), so this ptr2 won't point to anyhting
    //do this instead:
    std::cout << "uniquePtr1:  " << *uniquePtr1 << '\n';//now pointer1 is pointing to what pointer2 is pointing to  
   
  	return 0;
}

//The difference between the 2 is that shared pointers can point to memory that multiple things are pointing to
//unique pointers can only point to something that this alone is pointing to

