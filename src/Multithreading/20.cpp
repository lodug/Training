//hardware concurrency
//take a look at finding out how many threads we can genuinely run at the same time. And to do that, you just need to use a static member of the thread class.


#include <iostream>
#include <thread>

using namespace std;


int main()
{
    // included threads here and it's called hardware concurrency. That's a function.
    cout << thread::hardware_concurrency() << endl;
    return 0;
}