#include <iostream>

//not efficient if 
void printDigName(int x)
{
    if (x == 1)
        std::cout << "One";
    else if (x == 2)
        std::cout << "Two";
    else if (x == 3)
        std::cout << "Three";
    else
        std::cout << "Unknown";
}

//better use SWITCH
void printDigitName(int x)
{
    switch (x)  // IF x is evaluated to produce value 2
    {
        case 1:
            std::cout << "ONE";
            return;
            //return statements to stop execution of the statements after our labels. However, this also exits the entire function.
        case 2: // which matches the case statement here
            std::cout << "TWO"; // so execution starts here
            return; // and then we return to the caller
        case 3:
            std::cout << "THREE";
            return;
        default:
            std::cout << "UNKNOWN";
            return;           
    }
    // due to return execution stops adn this won't be printed
    std::cout << " Ah!";
}

//break statement :  (declared using the break keyword) tells the compiler that we are done executing statements within the switch, and that execution should continue with the statement after the end of the switch block. This allows us to exit a switch statement without exiting the entire function.
void printDgName(int x)
{
    switch (x) //x evaluates to 3
    {
        case 1:
            std::cout << "One";
            break;
        case 2:
            std::cout << "Two";
            break;  
        case 3:
            std::cout << "Three";
            break;
        default:
            std::cout << "Unknown";
            break;  
    }

    // execution continues here
    std::cout << " Ah-Ah-Ah!";
}

int main()
{
        printDigitName(2);
        std::cout << '\n';
        printDigName(2);
        std::cout << '\n';
        printDgName(3);
        std::cout << '\n';

        return 0;
}