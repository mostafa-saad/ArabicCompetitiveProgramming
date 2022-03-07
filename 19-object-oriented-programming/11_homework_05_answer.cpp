#include <bits/stdc++.h>
using namespace std;

class A {
public:
	int x = 1;

	void print() {
		cout << "I am A\n";
	}

	~A() {
		cout << "A Destructor\n";
	}

};

class B: public A {
public:
	int y = 2;

	void print() {
		cout << "I am B\n";
	}

	~B() {
		cout << "B Destructor\n";
	}
};

class C: public B {
public:
	int z = 3;

	void print() {
		cout << "I am C\n";
	}

	~C() {
		cout << "C Destructor\n";
	}
};

void hello(A* a) {
	// what is visible? only A members
	a->x = 1;
	a->print();
}

int main() {
	// Normal and each see his members and parents members
	C* c = new C();

	// As type eventually is A*, only what in A is visible
	// Looks like casting!
	A* a_points_c = new C();
	//a_points_c->z = 1;	// Compiler error

	// Observation: an object of a derived class can be treated as an object of its base class.
	// However, we cannot treat a base-class object as an object of any of its derived classes.

	hello(c);
	hello(a_points_c);

	// the invoked functionality depends on the type of the pointer used to invoke the function,
	// not the type of the object for which the member function is called.
	c->print();
	a_points_c->print();

	delete c;
	delete a_points_c;	// same as above. Destructor is a function. Only A destructor called. MEMORY LEAK

	return 0;
}

/*
I am A
I am A
I am C
I am A
C Destructor
B Destructor
A Destructor
A Destructor
 */
