#include <iostream>

void sort2(int& lesser, int& greater)
{
    // If the values are already sorted, we have nothing to do
    if (lesser <= greater)
        return;

    // Otherwise we need to swap the values
    int swap { lesser };
    lesser = greater;
    greater = swap;
}

int main()
{
    int x { 7 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n';

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n';

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n';

    return 0;
}