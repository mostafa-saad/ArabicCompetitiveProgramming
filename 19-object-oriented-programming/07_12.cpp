#include <bits/stdc++.h>
using namespace std;

class A {
private:
	int a1_private = 10;
	int a2_private = 20;

	void HiddenA() {
		cout << "I am hidden\n";
	}
public:
	// global friend function
	friend void PrintA(A& x);
};

void PrintA(A& x) {
	cout << x.a1_private << "\n";
	cout << x.a2_private << "\n";
	x.HiddenA();
}

int main() {
	A a;
	PrintA(a);

	return 0;
}
