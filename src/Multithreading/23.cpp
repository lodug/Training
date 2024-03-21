//distributing work between cores
// take a look at an actual example of distributing some CPU intensive work between multiple cores.

#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>
#include <iomanip>

using namespace std;

// skip is going to control what I add to pi every time. So this gives me a function that I can interleave; if I set start to zero and I set skip to one that
//will be the same as the function we originally had.
double calculate_pi(int terms, int start, int skip)
{
    double sum = 0.0;

    for (int i = start; i < terms; i += skip)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }

    return sum * 4;
}

int main()
{
    vector<shared_future<double>> futures;

    const int CONCURRENCY = thread::hardware_concurrency();

    for (int i = 0; i < CONCURRENCY; i++)
    {
        shared_future<double> f = async(launch::async, calculate_pi, 1E7, i, CONCURRENCY);
        futures.push_back(f);
    }

    double sum = 0.0;

    for (auto f : futures)
    {
        sum += f.get();
    }

    cout << setprecision(15) << "PI:  " << M_PI << endl;
    cout << setprecision(15) << "Sum: " << sum << endl;

    return 0;
}