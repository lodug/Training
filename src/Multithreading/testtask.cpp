#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

// void multithreading(int &var, mutex &mtx)
// {
//     for (int i = 0; i < 200000; i++)
//     {
//         lock_guard<mutex> guard(mtx);
//         var += 6;
//     }
// }

// int main()
// {
//     int count = 0;

//     mutex mtx;

//     thread t1(multithreading, ref(var), ref(mtx));
//     thread t2(multithreading, ref(var), ref(mtx));

//     t1.join();
//     t2.join();

//     cout << var << endl;

//     return 0;
// }



// void multithreading(int &var, mutex &mtx)
// {
//     for (int i = 0; i < 200000; i++)
//     {
//         mtx.lock();
//         var += 6;
//         mtx.unlock();
//     }
// }

// int main()
// {
//     int var= 0;

//     mutex mtx;

//     thread t1(multithreading, ref(var), ref(mtx));
//     thread t2(multithreading, ref(var), ref(mtx));

//     t1.join();
//     t2.join();

//     cout << var << endl;

//     return 0;
// }


class Task
{
private:
    int var = 0;
    mutex mtx;

public:
    void operator()()
    {
        for (int i = 0; i < 200000; i++)
        {
            const lock_guard<mutex> guard(mtx);
             var += 6;
        }
    }

    int getVar() 
    {
        return var;
    }
};

int main()
{
    Task task;

    thread t1(ref(task));
    thread t2(ref(task));

    // //let's wait for t1 to finish
    t1.join();
    t2.join();

    cout << task.getVar() << endl;

    return 0;
}

//three ways of running a thread. Well, we've only really seen one way of running a thread, but we can pass to this to the constructor of this thread.

//These thread objects we can pass function pointers, lambda expressions or callable objects.All three.