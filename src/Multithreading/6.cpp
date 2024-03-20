//use lock guards instead of mutex
//So as mentioned in the 5.cpp, using Mutexes directly is not ideal because you could get an exception thrown in the critical section and then it will never unlock.
//So for that reason we prefer to use RAII(Resource acquisition is initialization) 
//the idea is that if you want to acquire some resource, so in this case we want to acquire a lock, you do it by initializing some variable and then if that
//variable should go out of scope for any reason, even if an exception is thrown, then it will release  the resource or it can be made to do that.

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

void work(int &count, mutex &mtx)
{
    for (int i = 0; i < 1E6; i++)
    {
        //declare lock_guard(a template type)
        // this is a plain mutex called "guard" and we pass the mutex "mtx"
        //when you declare a lock guard and you you pass a mutex to it, it will actually acquire the lock if it can.
        //Otherwise it's going to wait until it can acquire the lock.
        //So basically it's the same as doing calling lock on a mutex, but when it goes out of scope, this is a different thing, it will release the lock.
        lock_guard<mutex> guard(mtx);
        ++count;
    } // when this bracket is hit, it is going out of scope
    //so every time we go around the loop, we're going to be acquiring the lock and then releasing the lock.
    //The critical section is it exists between line 24  and wherever the next sort of closing curly bracket is
}

int main()
{
    int count = 0;

    mutex mtx;

    thread t1(work, ref(count), ref(mtx));
    thread t2(work, ref(count), ref(mtx));

    t1.join();
    t2.join();

    cout << count << endl;

    return 0;
}