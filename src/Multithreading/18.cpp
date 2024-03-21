//blocking queuses: improve the 17.cpp
//a queue is a first in - first out data structure. It's one of the fundamental structures of computer programming like linked list or something stack queue.
//The idea of a queue is you can add items to it and you can remove items from it, always remove the item that's been in the queue for the longest (front of the queu)

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename E>
class blocking_queue
{
private:
    mutex _mtx;
    condition_variable _cond;
    int _max_size;
    queue<E> _queue;

public:
    blocking_queue(int max_size): _max_size(max_size)
    {

    }

    void push(E e)
    {
        unique_lock<mutex> lock(_mtx);

        _cond.wait(lock, [this](){ return _queue.size() < _max_size; });

        _queue.push(e);

        lock.unlock();
        _cond.notify_one();
    }

    //the fron method gets the front of the queue
    E front()
    {
        //add syncronization 
        unique_lock<mutex> lock(_mtx);
        //So what should front do if there is no item at the front because the queue is empty? And I think probably it would be most useful actually, if it just waits.
         _cond.wait(lock, [this](){ return !_queue.empty(); });

        return _queue.front();
    }

    void pop()
    {
        unique_lock<mutex> lock(_mtx);

        _cond.wait(lock, [this](){ return !_queue.empty(); });

        _queue.pop();

        lock.unlock();
        _cond.notify_one();
    }

    int size()
    {
        //add syncronization to the size method
        lock_guard<mutex> lock(_mtx);
        return _queue.size();
    }
};

int main()
{
    blocking_queue<int> qu(3);

    thread t1([&](){
        for(int i = 0; i < 10; i++)
        {
            cout << "pushing " << i << endl;
            cout << "queue size is " << qu.size() << endl;
            qu.push(i);
        }
    });

    thread t2([&](){
        for(int i = 0; i < 10; i++)
        {
            auto item = qu.front();
            qu.pop();
            cout << "consumed " << item << endl;
        }
    });

    t1.join();
    t2.join();
    
    return 0;
}