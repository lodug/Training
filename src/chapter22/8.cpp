#include <iostream>

template<typename T>
class Auto_ptr4
{
	T* m_ptr {};
public:
	Auto_ptr4(T* ptr = nullptr)
		: m_ptr { ptr }
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res{new Resource};
	return res; // this return value will invoke the move constructor
}

int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment

	return 0;
}

//The move constructor and move assignment operator are simple. 
//Instead of deep copying the source object (a) into the implicit object, we simply move (steal) the source object’s resources. 
//This involves shallow copying the source pointer into the implicit object, then setting the source pointer to null.

// The flow of the program is exactly the same as before. However, instead of calling the copy constructor and copy assignment operators, this program calls the move constructor and move assignment operators. Looking a little more deeply:

// Inside generateResource(), local variable res is created and initialized with a dynamically allocated Resource, 
//which causes the first “Resource acquired”.
// Res is returned back to main() by value. 
//Res is move constructed into a temporary object, transferring the dynamically created object stored in res to the temporary object. 
//We’ll talk about why this happens below.
// Res goes out of scope. Because res no longer manages a pointer (it was moved to the temporary), nothing interesting happens here.
// The temporary object is move assigned to mainres. This transfers the dynamically created object stored in the temporary to mainres.
// The assignment expression ends, and the temporary object goes out of expression scope and is destroyed. 
//However, because the temporary no longer manages a pointer (it was moved to mainres), nothing interesting happens here either.
// At the end of main(), mainres goes out of scope, and our final “Resource destroyed” is displayed.
// So instead of copying our Resource twice (once for the copy constructor and once for the copy assignment), 
//we transfer it twice. This is more efficient, as Resource is only constructed and destroyed once instead of three times.