#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

//changed the program from 4.cpp -  use a function instead of a lambda expression.
// nothing weird or special happens to the code that's between the lock and unlock of these mutexes. It's simply that only one thread can lock a mutex at any given time.

using namespace std;

//So we need to pass in mutex and count here so I can I can pass references into them.
void work(int &count, mutex &mtx)
{
    for (int i = 0; i < 1E6; i++)
    {
        mtx.lock();
        ++count;
        mtx.unlock();
    }
}

int main()
{
    int count = 0;   

    mutex mtx;   
 
    // I'll pass "work" to these threads. Pass a pointer to the function to the threads.
    //And now the question is how do I actually pass those arguments to work when it's invoked by.
    //pass by value count and mutex, and then thread passes those on to the function that it's calling.
    //thread t1(work, count, mtx);
    //because we need to pass a reference
    thread t1(work, ref(count), ref(mtx));
    thread t2(work, ref(count), ref(mtx));    

    t1.join();
    t2.join();

    cout << count << endl;

    return 0;
}

//it's not actually all that common to use mutexes because what happens with the code in the critical section, between lock and unlock?
//What happens if that throws an exception? Then your mutex will never get unlocked. So for that reason it's more common to use unique lock or lock guard. (see 6.cpp))