#include <bits/stdc++.h>
using namespace std;

class A {
public:
	virtual void f1(int x = 1) {
		cout<<x<<" in A\n";
	}
};

class B : public A {
public:
	// f1 will be called with A::f1 default params!
	void f1(int x = 2) {
		cout<<x<<" in B\n";
	}
};

int main() {
	A* a = new B();
	a->f1();	// 1 in B

	return 0;
}
