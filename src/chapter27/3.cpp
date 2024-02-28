#include <iostream>

void D() // called by C()
{
    std::cout << "Start D\n";
    std::cout << "D throwing int exception\n";

    throw - 1;

    std::cout << "End D\n"; // skipped over
}

void C() // called by B()
{
    std::cout << "Start C\n";
    D();
    std::cout << "End C\n";
}

void B() // called by A()
{
    std::cout << "Start B\n";

    try
    {
        C();
    }
    catch (double) // not caught: exception type mismatch
    {
        std::cerr << "B caught double exception\n";
    }

    try
    {
    }
    catch (int) // not caught: exception not thrown within try
    {
        std::cerr << "B caught int exception\n";
    }

    std::cout << "End B\n";
}

void A() // called by main()
{
    std::cout << "Start A\n";

    try
    {
        B();
    }
    catch (int) // exception caught here and handled
    {
        std::cerr << "A caught int exception\n";
    }

    std::cout << "End A\n";
}

int main()
{
    std::cout << "Start main\n";

    try
    {
        A();
    }
    catch (int) // not called because exception was handled by A
    {
        std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";

    return 0;
}

//Let’s examine what happens in this case. The printing of all the “Start” statements is straightforward and doesn’t warrant further explanation. 
//Function D() prints “D throwing int exception” and then throws an int exception. This is where things start to get interesting.

// Because D() doesn’t handle the exception itself, its callers (the functions up the call stack) are checked to see if one of them can handle the exception. 
//Function C() doesn’t handle any exceptions, so no match is found there.

// Function B() has a two try blocks. The try block containing the call to C() has a handler for exceptions of type double, 
//but that does not match our exception of type int (and exceptions do not do type conversion), so no match is found. The empty try block does have an exception handler for exceptions of type int, but this catch block is not considered a match because the call to C() is not within the associated try block.

// A() also has a try block, and the call to B() is within it, so the program looks to see if there is a catch handler for int exceptions. 
//There is! Consequently, A() handles the exception, and prints “A caught int exception”.

// Because the exception has now been handled, control continues normally at the end of the catch block within A(). 
//This means A() prints “End A” and then terminates normally.

// Control returns to main(). Although main() has an exception handler for int, our exception has already been handled by A(), 
//so the catch block within main() does not get executed. main() simply prints “End main” and then terminates normally.

//First, the immediate caller of a function that throws an exception doesn’t have to handle the exception if it doesn’t want to. In this case, C() didn’t handle the exception thrown by D(). It delegated that responsibility to one of its callers up the stack.

// Second, if a try block doesn’t have a catch handler for the type of exception being thrown, stack unwinding occurs just as if there were no try block at all. 
// In this case, B() didn’t handle the exception either because it didn’t have the right kind of catch block.

// Third, if a function has a matching catch block but the call to the current function did not occur within the associated try block, 
//that catch block isn’t used. We also saw this in B().

// Finally, once an exception is handled, control flow proceeds as normal starting from the end of the matching catch block. 
//This was demonstrated by A() handling the error and then terminating normally. 
//By the time the program got back to main(), the exception had been thrown and handled already -- main() had no idea there even was an exception at all!

// As you can see, stack unwinding provides us with some very useful behavior -- if a function does not want to handle an exception, 
//it doesn’t have to. The exception will propagate up the stack until it finds someone who will! 
//This allows us to decide where in the call stack is the most appropriate place to handle any errors that may occur.