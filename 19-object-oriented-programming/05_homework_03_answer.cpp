#include <bits/stdc++.h>
using namespace std;

class A {
private:
public:
	A() {
		cout<<"A Constructor\n";
	}
	~A() {
		cout<<"A Destructor\n";
	}
};

class B {
private:
public:
	B() {
		cout<<"B Constructor\n";
	}
	~B() {
		cout<<"B Destructor\n";
	}
};

class C {
private:
public:
	C() {
		cout<<"C Constructor\n";
	}
	~C() {
		cout<<"C Destructor\n";
	}
};

class D {
private:
	A aa;
	B bb;
	C cc;

public:
	D(const A &a, const B &b, const C &c) : aa(a), bb(b), cc(c){
		// By using & => we use same memory object hence faster and low memory
		// By using const => we remember developers you shouldn't try to change this parameter
	        // also this allow the user to pass temperory objects and const objects.
		// this allows to receive Rvalue and Lvalue not just Lvalue
	}
};

int main() {

	return 0;
}
