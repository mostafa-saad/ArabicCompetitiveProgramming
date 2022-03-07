#include <bits/stdc++.h>
using namespace std;

class A;	// Define early to break cycle

class B {
public:
	void AcessA1(A& x);
	void AcessA2(A& x);
};

class A {
private:
	int a1_private = 10;
	int a2_private = 20;

	void HiddenA() {
		cout << "I am hidden\n";
	}
public:
	// Friend function only access my private data
	friend void B::AcessA1(A& x);
};

void B::AcessA1(A& x) {
	cout << x.a1_private << "\n";
	x.HiddenA();
}
void B::AcessA2(A& x) {
	// Syntax error: can't access these private data
	//cout << x.a2_private << "\n";
	//x.HiddenA();
}

int main() {
	A a;
	B b;
	b.AcessA1(a);
	b.AcessA2(a);
	return 0;
}
