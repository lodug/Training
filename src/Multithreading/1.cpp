//basic multithreading program

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

//create a function that's going to contain some code that we want to run in its own thread.
void work()
{
    for (int i = 0; i < 10; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Loop" << i << '\n';
    }
};

int main() 
{
    thread t1(work);
    thread t2(work);
  
    t1.join(); 
    t2.join();
   
    return 0;
}


// int main() 
// {
//     //how can we run this code in its own thread?
//     //declare an object of the type thread using namespace standard: pass to  the constructor, a pointer to this function(just type the name of the function as below)
//     thread t1(work);
       //it outputs loop zero through to nine, but that's not very exciting. Let's try running two threads at the same time.//     
//     thread t2(work);

//     //I got an error. It says something about terminating. 
//     //But here what happens is this thread tries to run this code in its own thread.
//     // so the main thread just quits and that terminates this thread prematurely so the whole thing doesn't work.
//     //What we want to do here is wait until this thread has actually finished working before we quit the main program.
//     //So to do that I use the join method of the thread class. 
//     //It's just going to wait there until this thread is finished doing whatever it's doing.
//     t1.join(); 

//     t2.join();
   
       //So in this program so far we've got the main thread and that just creates another thread.

//So now there's two threads and the main thread waits for this second thread that it's just created until it quits
//So thread two, and I'll also use that to run the same function and we need to also add t to join.
// we get some output.
//And in this case, it's we've got one, two, three, four, five, six, seven, eight, nine, and then the same same thing again.
//But what's happened in this case is that this thread has started this code and the code is just finished running before this second thread could do anything.
//So it doesn't look multithreaded. It looks like we've just run this loop twice one after the other, which looks completely useless. 
//It looks here as though this is equivalent to just calling this function twice one after the other.
//What I need to do to really show that this is multithreaded is put a delay in this loop: include at the top chrono, 
//which is now a standard part of C plus plus and within the loop, let's write in the loop this_thread and pass to that chrono::milliseconds 500
//So this this is a way of getting whatever the current thread is, whatever the thread this is in, it'sa wa 
//y for getting the thread to sleep for, well, in this case, 500 milliseconds at a time.
// It's a standard part of C plus plus.


// Now let's try our program again, so I'm going to compile it.
// And I'm going to run it.
// And now we see something quite different.
// So the output from the two threads is interleaved and in fact, it's also mangled.
// I'm actually finding that in some cases one thread can output loop and then it doesn't manage to output the number before the other.
// Thread also outputs loop.
// So it's not kind of tidy output at all.
// Now we're going to delve into this and I'm going to talk about what's what's going on and how to make threads cooperate properly with each other.

// And the point is that these two threads are running essentially at the same time.
// This thread is running its code essentially at the same time as this thread here.
// And that's why we're getting interleaved output and we can start lots of threads and run them all at the same time.

//     return 0;
// }

//NOTE: compile the code using: g++ 1.cpp -pthread (not compiling otherwise, because the linker cannot find the 
// implementation of pthread_creation which is a function part of POSIX threading library, required for the std::thread implementation on many platforms, including Linux)