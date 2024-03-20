//packaged Tasks:  these basically allow us to work with promises and futures, but in a way that's nicer than if we work with them directly.
//we'll learn how to run the code in its own thread using a package task

#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <iomanip>

using namespace std;

double calculate_pi(int terms)
{
    double sum = 0.0;

    if (terms < 1)
    {
        throw runtime_error("Terms cannot be less than 1");
    }

    for (int i = 0; i < terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }

    return sum * 4;
}

int main()
{
    //a template type with a function that returns a double and has an argument which is an int
    packaged_task<double(int)> task1(calculate_pi);
    //So the function that you pass to the task constructor, you want that to return a value and that gets stored in a promise which we can get via.
    //We can get the value of that via a future.So this basically achieves what we did in the 10.cpp, but a lot more simply exceptions work as well.

    // A future that is gonna return a double
    //So we get the future immediately, and from that we can ultimately get a return value.
    //So after we've run the thread, we'll be able to get the return value from the future.
    future<double> future1 = task1.get_future();

    //create a thread called T1 and pass the packaged task to this
    //move is just saying, look, create a sort of shallow copy of this and then copy into it any resources
    //that it's using pointers to memory or whatever, just in fact just move them.So the old one is not necessarily left in a state that's any use.
    thread t1(move(task1), 1E6);
    //  thread t1(move(task1), 0); TO THROW THE EXCEPTION

    try
    {
        //call future, get and that should be a double value
        double result = future1.get();
        //output the result
        cout << setprecision(15) << result << endl;
    }
    //try catching exception reference e
    catch (exception &e)
    {
        cout << "ERROR! " << e.what() << endl;
    }

    //let's wait for t1 to finish
    t1.join();

    return 0;
}

//If you throw an error, then you can catch it later on. So we've not mixed any multithreading code with calculate pi, it just calculates the result.
//It throws an exception. If something goes wrong, we pass that to package task and from the task we can immediately get a future.
//We move the task to a thread then and we run it in a try.Catch and a try catch will catch any exception that's thrown ultimately in this case from calculate pi.
//We don't we didn't have to mention promise directly at all.