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
	D() : bb(B()), aa(A()), cc(C()){
		cout<<"D Constructor\n";
	}
	~D() {
		cout<<"D Destructor\n";
	}
};

int main() {
	D d;

	return 0;
}
/*
A Constructor
B Constructor
C Constructor
D Constructor
D Destructor
C Destructor
B Destructor
A Destructor


From results: Constructors are called based on Class data members order NOT initalizer list order
 */
