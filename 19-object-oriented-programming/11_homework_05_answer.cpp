#include <bits/stdc++.h>
using namespace std;

class A {
public:
	int x = 1;
	~A() {
		cout<<"A Destructor\n";
	}
};

class B: public A {
public:
	int y = 2;
	~B() {
		cout<<"B Destructor\n";
	}
};

class C: public B {
public:
	int z = 3;

	~C() {
		cout<<"C Destructor\n";
	}
};

void hello(A* a) {
	// what is visible? only A members
	a->x = 1;
}

int main() {
	// These 3 are normal and each see his members and parents members
	A* a1 = new A();
	B* b1 = new B();
	C* c1 = new C();

	// These 2 are weird. As type eventually is A*, only what in A is visible
	// Looks like casting!
	A* b2 = new B();
	A* c2 = new C();
	//b2->y = 1;	// Compiler error

	hello(c1);
	hello(c2);

	delete a1;
	delete b1;
	delete c1;

	delete b2;
	delete c2;

	return 0;
}

// TODO
