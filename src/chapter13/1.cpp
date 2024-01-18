#include <iostream>

namespace Colors
{    
    enum Colors
    {
        pink,
        brown,        
    };
}

int main()
{
     Colors::Colors shirt{ Colors::pink };

    // if (shirt == blue) // if the shirt is blue
    //     std::cout << "Your shirt is blue!";
    // else
    //     std::cout << "Your shirt is not blue!";
   
    if (shirt == Colors::pink ) 
        std::cout << "Your shirt is pink!";
    else
        std::cout << "Your shirt is not pink!";

    return 0;
}

// enum Color
// {
//     red,
//     green,
//     blue,
// };

// int main()
// {
//     Color shirt{ blue };

//     if (shirt == blue) // if the shirt is blue
//         std::cout << "Your shirt is blue!";
//     else
//         std::cout << "Your shirt is not blue!";

//     return 0;
// }