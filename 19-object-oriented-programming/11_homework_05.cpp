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
	a->x = 1;
	a->print();
}

int main() {
	C* c = new C();
	A* a_points_c = new C();

	hello(c);
	hello(a_points_c);

	c->print();
	a_points_c->print();

	delete c;
	delete a_points_c;

	return 0;
}
