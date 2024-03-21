//waiting  for threads
//But this is hardly optimal because we have to check ready every 100 milliseconds. in 13.cpp will se an optimal solution for this code

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;


// create a situation where the main thread has to wait for the thread  t1 to do something.
// got two threads in this program.

int main()
{
    atomic<bool> ready(false);

    //this thread has got to do something which the main thread is then waiting for.
    //capture local variables by reference here so I can use it in my lambda expression.
    thread t1([&](){

        this_thread::sleep_for(chrono::milliseconds(2000));
        //this thread set ready to true; put a delay to take some time to do it
        ready  = true;
    });

    t1.join();

    //How can we figure out when it's time for the main thread that's waiting for this to become true, for that to proceed?
    // I'm going to make this check every 100 milliseconds. If ready is true yet and when we finish waiting for this, 
    //I'm going to do cout and let's output the value of ready just to be 100% certain. So this is going to say, okay, 
    //so while ready is false, it's going to sleep for 100 milliseconds.
    while(!ready)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "ready " << ready << endl;



    return 0;
} 