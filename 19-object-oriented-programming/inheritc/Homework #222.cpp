#include <bits/stdc++.h>
using namespace std;

class A {
protected:
	int px;
	void pf() {
	}
};

class B {
protected:
	int px;
	void pf() {
	}

	int GetSalary() {
		return 100;
	}
};

class C: public A, public B {
public:
	void f() {
		// If common data/function, use resolution operator to specificy which one as compiler will be confused (Ambiguity)
		A::px = 1;		// to access px from A
		B::pf();		// to access pf from B
	}

	int GetSalary() {
		// The developer wanted to call parent GetSalary, but his method is same name
		// This will be infinite recursion. Again access parent clearly by B::
		int parent_salary = B::GetSalary();
		return 2 * parent_salary + 1;
	}
};

int main() {
	C c;
	cout<<c.GetSalary();

	return 0;
}
