#include <iostream>

class A
{
public:
    void print()
    {
        std::cout << "A";
    }
    virtual void vprint()
    {
        std::cout << "A";
    }
};
class B : public A
{
public:
    void print()
    {
        std::cout << "B";
    }
    void vprint() override
    {
        std::cout << "B";
    }
};


class C
{
private:
    A m_a{};

public:
    virtual A& get()
    {
        return m_a;
    }
};

class D : public C
{
private:
    B m_b{};

public:
    B& get() override // covariant return type
    {
        return m_b;
    }
};

int main()
{
    // case 1
    D d {};
    d.get().print();
    d.get().vprint();
    std::cout << '\n';

    // case 2
    C c {};
    c.get().print();
    c.get().vprint();
    std::cout << '\n';

    // case 3
    C& ref{ d };
    ref.get().print();
    ref.get().vprint();
    std::cout << '\n';

    return 0;
}

//In all cases, because get() has a covariant return type, the return type of get() will be the return type of the get() member function of the implicit object.

//Case 1 is straightforward. In both statements, d.get() calls D::get(), which returns m_b. Because get() is being called on d, which is of type D, the return type of D::get() is used, which is type B&. The calls to print() and vprint() resolve to B::print() and B::vprint() respectively.

//Case 2 is also straightforward. In both statements, c.get() calls C::get(), which returns m_a. Because get() is being called on c, which is of type C, the return type of C::get() is used, which is type A&. The calls to print() and vprint() resolve to A::print() and A::vprint() respectively.

//Case 3 is the interesting one. ref is a C& referencing a D. ref.get() is a virtual function, so ref.get() virtually resolves to D::get(), which returns m_b. However, get() has a covariant return type, so the return type of get() is determined by the type of the implicit object that get() is called on. Since ref is a C&, the return type of C::get() is used, which means the return type of ref.get() is A& (referencing object m_b, which is a B).

//Because the return type of ref.get() is an A&, non-virtual function call ref.get().print() resolves to A::print().

//When virtual function ref.get().vprint() is called, virtual function resolution is used. Although the return type of ref.get() is an A&, the object being reference is actually a B. Therefore, B::vprint() is called.