//mutexes: modifiy the 3.cpp

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

using namespace std;

int main()
{
    int count = 0;
    const int ITERATIONS = 1E6;

    mutex mtx;

    // pass a reference to it to the lambda expression, & capture any local variables.
    auto func = [&]() {
        for (int i = 0; i < ITERATIONS; i++)
        {
            //we lock before we mess with the count, before we do anything with it. And after that we do  mtx.unlock
            // find that the value is always 2 million or twice whatever we set that iterations
            //The mutex here stops more than one thread at a time from accessing this variable between lock and unlock here.
            //Any code that's in here we call a critical section.The point about a critical section is that only one thread can access it at a time, 
            //so only one thread can lock the mutex at a given time. 
            //If another thread tries to lock the mutex when it's already locked, that second thread will just wait 
            //until the mutex is unlocked and then the second thread will be able to lock the mutex.
            //And one of the important things about this is that you've got to unlock the mutex.
            mtx.lock();
            ++count;
            mtx.unlock();
            //So the region of code that you want to surround with lock and unlock, you want to make that as small as possible.
            //You want it to only be the stuff that is shared between threads.            
        }
    };

    thread t1(func);
    thread t2(func);

    t1.join();
    t2.join();

    cout << count << endl;

    return 0;
}


// int main()
// {
//     //atomic<int> count(0);
//     //now with the line commented above, the result on some computers can be less that expected
//     int count  = 0;

//     // a variable that controls how many iterations the loops written will going to do
//     const int ITERATIONS  = 1E6;

//     //got rid of the code dupplication from 3.cpp :  set that equal to this lambda expression.
//     //So although the lambda expression is anonymous, we can have a reference to it so that we can reuse it.
//     auto func = [&count]()
//     {
//         for (int i = 0; i < ITERATIONS; i++)
//             {
//                 ++count;
//             }
//     };
   
//     //pass func to the constructor of these threads. it will output the same as before (under 2 millions and this is not ok)
//     //but in order to fix this problem)
//     thread t1(func);   
//     thread t2(func);

//     //So one way to fix this, which is a much more general way that will work even if rather than an incrementing
//     //a variable, you're for example, adding two vectors or deleting from vectors or whatever is to use
//     //locks and critical sections. Now for this you might need to include mutex mutex, so create a mutex. see the program uncommented with the right code

//     t1.join();
//     t2.join();
    
//     cout << count << endl;   

//     return 0;
// }