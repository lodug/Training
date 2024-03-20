//create threads using callable objects

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

//the program 6.cpp will be modified: instead of using the work function, it uses an object or a class.
//So a callable object is an object of a class that overloads the call operator.
class App
{
private:
    int count = 0;
    mutex mtx;

public:
    // void work()
    //If instead of that, we want to overload the call operator, then we just get rid of this work here and put operator() instead:
    void operator()()
    {
        for (int i = 0; i < 1E6; i++)
        {
            const lock_guard<mutex> guard(mtx);
            ++count;
        }
    }

    int getCount() 
    {
        return count;
    }
};

int main()
{
    //create an istance of app
    App app;

    //simply pass this instance of an app;pass a reference to app to our thread
    thread t1(ref(app));
    thread t2(ref(app));

    t1.join();
    t2.join();

    cout << app.getCount() << endl;
   // We should find that our count variable is 2 million or it's just going to be twice whatever you've set this to because we're running two threads.

    return 0;
}