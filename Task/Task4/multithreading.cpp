//Task4: multithreading: implement a task that treats the value of an extern variable that is read, modified and printed by 2 threads in parallel in a safe way

//used mutex for safety: only one thread can access the variable at a time.

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

//function that will modify the variable var
void multithreading(int &var, mutex &mtx)
{
    for (int i = 0; i < 200000; i++)
    {
        //lock the mutex before to access the variable 
        lock_guard<mutex> guard(mtx);

        //modifiy the variable
        var += 6;
    }
}

int main()
{
    int var = 0;

    mutex mtx;

    //create threads
    thread t1(multithreading, ref(var), ref(mtx));
    thread t2(multithreading, ref(var), ref(mtx));

    //let's wait for t1 to finish
    t1.join();
    //let's wait for t1 to finish
    t2.join();

    //print the value 
    cout << var << endl;

    return 0;
}

