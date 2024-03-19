//shared data: what problem arises when threads share data
//We'll take a look in particular at Lambda expressions.
//There are various things that we can pass to the constructor of thread. We can actually pass a lambda expression here and we can pass a callable object.

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

int main()
{
    atomic<int> count(0);
    //int count  = 0;

    // a variable that controls how manu iterations the loops written will going to do
    const int ITERATIONS  = 1E6;

    //  pass a lambda expression(It's just an anonymous function, like a function that doesn't have a name, 
    //  so something you probably in this case you only want to call it once, although you can store like a reference to it.) to this thread t1 and t2
    // [](){} - these serves a purpose in lamda expressions:
    // [] =  are capture brackets that we use to say what essentially what variables from its environment the lambda expression can use.
    // {} = where the code goes
    // () -= used for passing parameters
    // pass a lamda expression to thread 2 as well
    thread t1([&count]()
    {
        for (int i = 0; i < ITERATIONS; i++)
        {
            ++count;
        }

    });

    //what happens if another thread increments count at the same time?
    thread t2([&count]()
    {
        for (int i = 0; i < ITERATIONS; i++)
        {
            ++count;
        }

    });

    t1.join();
    t2.join();

    //we print it here because we want to make sure that we wait for the thread to finish before we output count.
    cout << count << endl;

    //there can be a problem with Multithreading that if you've got multiple threads operating on the same data, they will usually mess up each other's efforts (they 
    //will not print the 2millions for example in this case on some computers, but other random stuff).
    // to fix this problem, but it will work only for this simple case  where we're just incrementing an integer), 
    //not when you want multiple threads to operate on the same data; we added atomic to the int variable on line 14 instead of line 15 (the only modification)
    
    return 0;
}