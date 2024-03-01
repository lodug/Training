#include <iostream>

int main()
{
    int x {};
    const int* ptr{ &x }; // assume 4 byte ints

    std::cout << ptr << ' ' << (ptr + 1) << ' ' << (ptr + 2) << '\n';

    int y {};
    const int* ptr1{ &y }; // assume 4 byte ints

    std::cout << ptr1 << ' ' << (ptr1 - 1) << ' ' << (ptr1 - 2) << '\n';


    return 0;
}

//Given some pointer ptr, ptr + 1 returns the address of the next object in memory (based on the type being pointed to). So if ptr is an int*, and an int is 4 bytes, 
//ptr + 1 will return the memory address that is 4 bytes after ptr, and ptr + 2 will return the memory address that is 8 bytes after ptr.
//each memory address is 4 bytes greater than the previous.

//each memory address is 4 bytes less than the previous. (in the case of difference)