//Using Methods in Threads

//blocking queuses
//a queue is a first in - first out data structure. It's one of the fundamental structures of computer programming like linked list or something stack queue.
//The idea of a queue is you can add items to it and you can remove items from it, always remove the item that's been in the queue for the longest (front of the queu)

#include <iostream>
#include <thread>

using namespace std;

//how to call methods from threads:
//this will be a template class
template<typename E>
class blocking_queue
{
public:
    //add items to the queue of type E
    void push(E e)
    {
        cout << "push" << endl;
    }

    //RETURNS items and at the same time removes them from the queue
    void pop()
    {
        cout << "pop" << endl;
    }
};

int main()
{
    //create a blocking queue
    blocking_queue<int> qu;

    //call push (template to be taken into account); going to need probably a & to make sure that we get a kind of pointer to that function and we
    //need to supply also the function, the address of the object that we intend to associate this with. 7 is the element e
    //So we've got the object and the method that we want to call on that object.
    thread t1(&blocking_queue<int>::push, &qu, 7);
    thread t2(&blocking_queue<int>::pop, &qu);

    t1.join();
    t2.join();
    
    return 0;
}