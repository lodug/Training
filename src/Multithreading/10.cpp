//promises and exceptions

#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <future>
#include <exception>

using namespace std;

double calculate_pi(int terms)
{
    double sum = 0.0;

    //exception
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
    promise<double> promise;

    auto do_calculation = [&](int terms) {
        try
        {
            auto result = calculate_pi(terms);
            promise.set_value(result);
        }
        catch (...)
        {
            //This is all from the standard library STD, colon, colon to get an exception pointer object that refers
            //to the exception that's actually been thrown and we set that into the promise and set exception will
            //cause future.get to return just in the same way that it's set value causes it to return.
            promise.set_exception(current_exception());
        }
    };

    thread t1(do_calculation, 1E6);
    //thread t1(do_calculation, 0); 0 number of terms for testing the exception (< 1, nr de termeni < 1)

    future<double> future = promise.get_future();

    try
    {
        cout << setprecision(15) << future.get() << endl;
    }
    catch (const exception &e)
    {
        //we'll use the "what" method of the exception class to actually get the message from it.
        cout << e.what() << endl;
    }

    t1.join();
    return 0;
}