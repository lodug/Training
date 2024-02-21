#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    std::size_t length { arr.size() };

    for (std::size_t index{ 0 }; index < length; ++index)
    {
        std::cout << arr[index] << ' ';
    }

    if (arr.size() > 0)
        std::cout << '\n';
}

int main()
{
    std::vector<int> arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr);

    return 0;
}

// #include <iostream>
// #include <vector>

// int main()
// {
//     std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
//     std::size_t length { arr.size() };

//     for (std::size_t index{ 0 }; index < length; ++index)
//     {
//         std::cout << arr[index] << ' ';
//     }

//     if (arr.size() > 0)
//         std::cout << '\n';

//     return 0;
// }