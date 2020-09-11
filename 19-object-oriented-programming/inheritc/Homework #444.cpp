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

int main() {
	A* a1 = new A();
	B* b1 = new B();
	C* c1 = new C();

	A* b2 = new B();
	A* c2 = new C();

	delete a1;
	delete b1;
	delete c1;

	delete b2;
	delete c2;

	return 0;
}

// TODO
