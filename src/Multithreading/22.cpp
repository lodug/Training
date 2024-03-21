// a thread pool

#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>
#include <queue>

using namespace std;

mutex g_mtx;

template <typename E>
class blocking_queue
{
private:
    mutex _mtx;
    condition_variable _cond;
    int _max_size;
    queue<E> _queue;

public:
    blocking_queue(int max_size) : _max_size(max_size)
    {
    }

    void push(E e)
    {
        unique_lock<mutex> lock(_mtx);

        _cond.wait(lock, [this]() { return _queue.size() < _max_size; });

        _queue.push(e);

        lock.unlock();
        _cond.notify_one();
    }

    E front()
    {
        unique_lock<mutex> lock(_mtx);
        _cond.wait(lock, [this]() { return !_queue.empty(); });

        return _queue.front();
    }

    void pop()
    {
        unique_lock<mutex> lock(_mtx);

        _cond.wait(lock, [this]() { return !_queue.empty(); });

        _queue.pop();

        lock.unlock();
        _cond.notify_one();
    }

    int size()
    {
        lock_guard<mutex> lock(_mtx);
        return _queue.size();
    }
};

int work(int id)
{
    unique_lock<mutex> lock(g_mtx);
    cout << "Starting " << id << endl;
    lock.unlock();

    int seconds = int((5.0 * rand()) / RAND_MAX + 3);
    this_thread::sleep_for(chrono::seconds(seconds));

    return id;
}

int main()
{
    // Here the argument supplied to the queue needs to be
    // one less than the number of threads you want to launch.
    blocking_queue<shared_future<int>> futures(2);

    thread t([&]() {
        for (int i = 0; i < 20; i++)
        {
            shared_future<int> f = async(launch::async, work, i);
            futures.push(f);
        }
    });

    for (int i = 0; i < 20; i++)
    {
        shared_future<int> f = futures.front();
        int value = f.get();
        futures.pop();
        cout << "Returned: " << value << endl;
    }

    t.join();

    return 0;
}

//That's our thread pool.In this case, we're working through 20 threads that are all doing something, but we only run three threads at a time.
//And typically if we had CPU intensive work, we'd want to fire off a number of threads at a given time.
//That's equal to, of course the number of threads that we can genuinely run simultaneously equal to our hardwareconcurrency.
//It's extremely useful if you've got a bunch of threads that you want to run because you don't usually want to run them all at the same time.