int foo()
{
    return 5;
}

int main()
{
    int x { 5 };
    &x; // compiles: x is an lvalue expression
    &5; // doesn't compile: 5 is an rvalue expression
    &foo(); // doesn't compile: foo() is an rvalue expression
    
}

//If you’re not sure whether an expression is an lvalue or rvalue, try taking its address using operator&, which requires its operand to be an lvalue. If &(expression); compiles, expression must be an lvalue: