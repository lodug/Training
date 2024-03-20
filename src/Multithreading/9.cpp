//promises and futures: used to get return values from threads
//how we can get results from threads 
// how we can use promises and futures to get a simple result from a thread that, for example, calculates Pi or does whatever you want it to do.


#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <future> //promise is included in it

using namespace std;

double calculate_pi(int terms) 
{
    double sum = 0.0;

    for(int i = 0; i < terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0/(i * 2 + 1);
        sum += sign * term;
    }

    return sum * 4;
}

int main()
{
    //to get the result of the function, declare a promise that encapsulate the type double
    promise<double> promise;
    
    //create the lamda expression
    //pass here int terms and we want do calculation to be able to use this promise.
    //put a sign & so that we want to capture all local variables by reference.
     auto do_calculation = [&](int terms)
    {
        //call the function
        auto result = calculate_pi(terms);
        //We're going to use it to set and get a double type, which is the return value of our function.
        //when the threads runs, it can use the promise to set the return result
        //set the result into promise
        promise.set_value(result);
    };

    //And then I can run the lambda expression here, do calculation, and I pass in a number of terms that I want it to calculate
    thread t1(do_calculation, 1E6);

    //esult set the result into the promise.

    //Now, in our main thread, we're able to obtain that vlaue(result), and the way we do it is via a thing called a future.
    //the future and promise work together
    //the future is dealing with a double result type and the second future is the future that we get from the promise
    future<double> future = promise.get_future();

     cout << setprecision(15) << future.get() << endl; //THIS WILL get the result that we set into the promise with set value (line 43)
     //get is a blocking function so it gets won't return until you do set value in promise in your thread.
     //So this will just pause at this point and eventually when this thread does promise.set value, then future.get will return and will output the value.


    // //we want to run the function above in its own thread 
    // //create a thread T1 and pass the function pointer to it and pass by value the number of terms that I want it to include in the approximation:
    // thread t1(calculate_pi, 1E6);

    t1.join();



}