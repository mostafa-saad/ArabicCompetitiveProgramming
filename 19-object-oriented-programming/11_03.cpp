#include <bits/stdc++.h>
using namespace std;

class A {
public:
	int x;
	int y;
	A(int x, int y = 20) :
			x(x), y(y) {
	}
};

class B: public A {
	int z;
public:
	// C++1 inheriting base class constructors
	using A::A;
};

int main() {
	B b(3);
	cout<<b.x<<" "<<b.y;	// 3 20
	return 0;
}

