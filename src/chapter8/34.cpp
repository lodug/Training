#include <iostream>

// int main()
// {
//     for (int count{ 0 }; count < 10; ++count)
//     {
//         // if the number is not divisible by 4...
//         if ((count % 4) != 0) // nested block
//         {
//                 // Print the number
//                 std::cout << count << '\n';
//         }
//     }

//better to write the abve code like this:
int main()
{
    for (int count{ 0 }; count < 10; ++count)
    {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue;

        // no nested block needed

        std::cout << count << '\n';
    }

    return 0;
}
