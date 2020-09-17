#include <bits/stdc++.h>
using namespace std;

class A {
public:
	A(string str) {	cout<<"Constructor "<<str<<"\n";	}
	~A()		  {	cout<<"~A\n";	}
};

class B {
	A a1;
public:
	B() : a1(A("Most")) {
		cout<<"Constructor B"<<"\n";
	}
	~B()		  {	cout<<"~B\n";	}
};

class C : public B{
	A a2;
public:
	C() : a2(A("Ali")) {
		cout<<"Constructor C"<<"\n";
	}
	~C() 		{	cout<<"~C\n";	}
};

int main() {
	C c1;
	C* c2;
	return 0;
}

/*

This is an exmple for both inheritance and composition

Constructor Most
Constructor B
Constructor Ali
Constructor C
~C
~A
~B
~A


Note, this pointer is not created = no output

Also note: Destroctor doesn't mean destroying

Construction:
	Derived allocated
	Base allocated
	Base constructor called
	Derived constructor called

Destruction:
	Derived destructor called
	Base destructor called
	Base deallocated
	Derived deallocated

Src: https://stackoverflow.com/questions/654428/what-is-the-order-in-which-the-destructors-and-the-constructors-are-called-in-c

 */
