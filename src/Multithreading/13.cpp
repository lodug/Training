// Condition Variables

#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>

using namespace std;

int main()
{
    condition_variable condition;
    //need a mutex because a condition variable works together with a mutex 
    mutex mtx;
    //not an atomic ball because we're going to implement proper thread synchronization now with critical sections and this guarantees that all variables, the
    //state of them will be visible to all threads.
    bool ready = false;

    thread t1([&](){
        this_thread::sleep_for(chrono::milliseconds(2000));
        //a mutex lock of type mutex
        //So the reason I'm using unique lock and not lock guard is that I need the unlock method. So after I've set ready to true, I'm going to call lock.unlock.s
        //o I'm going to call the unlock method of unique lock
        //after 2 seconds it will try to get a lock
        unique_lock<mutex> lock(mtx);
        //When it does get the lock, it says ready equals true and then it unlocks the lock.
        //And after unlocking the lock, it notifies using the condition waiting threads that it can that they can wake up.
        //And in this case, we've got one waiting thread. So we use notify one and we use notify one whenever we intend to wake up one waiting thread.
        ready = true;
        lock.unlock();
        //call the condition.notify (exists 2 methods: notify_one and notify_all)
        condition.notify_one();
    });

    //Both of these unique locks need to get the lock associated with the same mutex.
    //So to the constructor of these unique "lock" objects, I need to supply the mutex that we're going to lock on; we have "lock" also above; they are connected
    unique_lock<mutex> lock(mtx);

    while(!ready)
    {
        // we do condition wait and that actually releases the lock associated with mtx, tge lock from above lock(mtx) line 25
        condition.wait(lock);
    }

    cout << "ready " << ready << endl;

    t1.join();
    return 0;
}